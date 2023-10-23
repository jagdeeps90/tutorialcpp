/*
Burger equation: using pseduo-spectral FG method:
∂u/∂t + u * ∂u/∂x = ν * ∂²u/∂x²
Libraries: Eigen and FFTW3
Compile: g++ -std=c++17 -o binaryfilename filename.cpp -I /path/to/Eigen/ -lfftw3
*/


#define _USE_MATH_DEFINES
#include <fftw3.h>
#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <random>
#include <vector>
#include <fstream>

using namespace std;
using namespace Eigen;



VectorXd generateBurgersNoise(double alpha, int m) {
    // Seed for random number generator
  
    srand((unsigned) time(NULL));
    int random = rand();
    random_device rd;
    mt19937 gen(rd());
    //normal_distribution<double> normal(0.0, 1.0);
    uniform_real_distribution<double> dist(-1.0, 1.0);
   // VectorXd x(m);
    VectorXcd xft(m/2 + 1);
    VectorXcd x1ft(m/2 + 1);
    VectorXd x1(m);
    
    VectorXd x =  sqrt(m) * (VectorXd::Random(m));
    /*
    for (int i = 0; i < m; i++) {
        x(i) = sqrt(m)*dist(gen);
    }
    */
   // cout<<x<<endl;
    fftw_plan random_forward_plan = fftw_plan_dft_r2c_1d(m, x.data(), reinterpret_cast<fftw_complex*>(xft.data()), FFTW_ESTIMATE);

    fftw_execute(random_forward_plan);
    
    for (int freq = 0; freq < (m / 2 + 1); freq++) {
        double freq_magnitude = abs(freq);
        complex<double> scaling_factor(1.0, 0.0);  // Initialize to 1 for low frequencies
        if (freq_magnitude > 0.0) {
            scaling_factor = complex<double>(pow(freq_magnitude, -alpha/2.0), 0.0);
        }
        x1ft(freq) = xft(freq) * scaling_factor;
    }
     //cout<<xft<<endl;
    // cout <<x1ft<<endl;
    
    //x1ft(m/2+1) = 0;
    fftw_plan random_backward_plan = fftw_plan_dft_c2r_1d(m, reinterpret_cast<fftw_complex*>(x1ft.data()), x1.data(), FFTW_ESTIMATE);

    fftw_execute(random_backward_plan);

    x1 /= m;

    // Clean up
    fftw_destroy_plan(random_forward_plan);
    fftw_destroy_plan(random_backward_plan);

    return x1;
}


int main() {
    //Simulation parameters
    int p = 12;
    int N = pow(2,p);
    int Nh = N/2.0 + 1;
    double L = 2.0* M_PI;
    double dx = L/N;
    double nu = 0.005;
    double t_start = 0.0;
    double t_end =   10;
    double t = t_start;
    double dt = 1e-6; // Use a ∆t based on CFL
    double D = 1;
    double alpha = 1;
    //Real vector
    VectorXd x(N);
    VectorXd ux(N);
    VectorXd dux(N);
    VectorXd ddux(N); 
    VectorXd force_un(N);
    VectorXd force_uo(N);
    VectorXd f(N);
    VectorXd ff(N);

    //complex vectors
    VectorXd k(Nh); 
    VectorXcd uk(Nh);
    VectorXcd duk(Nh);
    VectorXcd dduk(Nh);
    srand((unsigned) time(NULL));
    int random = rand();
    ofstream outputFile;
    int outputInterval = 100;
    int outputCounter = 0;
  //initial condition
  
  for(int i=0;i<N;++i){
      x(i) = i*dx;
      ux(i) = sin(x(i));
  }



  while(t<t_end){
  
      f = generateBurgersNoise(alpha,N);
      
      fftw_plan forward_plan = fftw_plan_dft_r2c_1d(N, ux.data(), reinterpret_cast<fftw_complex*>(uk.data()), FFTW_ESTIMATE);

      fftw_execute(forward_plan);
  // Calculate k values,duk and dduk in spectral space
      for (int i = 0; i < Nh; ++i) {
          //k(i) = complex<double>((2.0 * M_PI * i) / L,0.0);
          k(i) = (2.0 * M_PI * i) / L;
          duk(i) = complex<double>(0.0, 1.0) * k(i) * uk(i);
          dduk(i) = -k(i) * k(i) * uk(i);
      }
      
      fftw_plan dux_plan = fftw_plan_dft_c2r_1d(N, reinterpret_cast<fftw_complex*>(duk.data()), dux.data(), FFTW_ESTIMATE);
      fftw_plan ddux_plan = fftw_plan_dft_c2r_1d(N, reinterpret_cast<fftw_complex*>(dduk.data()), ddux.data(), FFTW_ESTIMATE);
      fftw_execute(dux_plan);
      fftw_execute(ddux_plan);


  // Scale the result of the IFFT to match the original U
      dux /= N;
      ddux /=N;
      
      for (int i=0;i<N;++i){
        ff(i) = sqrt(2.0*D/dt) * f(i);
        force_un(i) = -ux(i)*dux(i) + nu * ddux(i) + sqrt(2.0*D/dt)*f(i);
        
        if (t==0){
          ux(i) = ux(i) + dt * force_un(i);
         }
        else {
        ux(i) = ux(i) + dt * ((3.0/2.0) * force_un(i) - (1.0/2.0)* force_uo(i)); //adam bashforth scheme
         }
       force_uo(i) = force_un(i);
      }
      fftw_destroy_plan(forward_plan);
      fftw_destroy_plan(dux_plan);
      fftw_destroy_plan(ddux_plan); // Clean up the plans
    

    t+=dt;

    
    outputCounter++;

            // Save data every 100 time steps
          if (outputCounter == outputInterval) {
              outputCounter = 0;
              // Open a new output file with a name based on the current time step
              outputFile.open("t" + to_string(static_cast<int>(t * 100)+ 1) + ".txt");

              // Save x(i) and ux(i) to the output file
              for (int i = 0; i < N; ++i) {
                  outputFile << x(i) << " " << ux(i)<< " " <<ff(i)/ff.maxCoeff()<< endl;
              }

              // Close the output file
              outputFile.close();
          }
      
      


      }

  
  return 0;
}
            // Clean up the plans

    



