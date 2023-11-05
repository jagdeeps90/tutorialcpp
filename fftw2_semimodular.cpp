/*
 * This code is written by @Jagdeep
 This example shows a simple demonstration of fftw library.

*/
#include <iostream>
#include <Eigen/Dense>
#include <fftw3.h>
#include <random>
using namespace std;
using namespace Eigen;


VectorXd random_generator(int& M){

    srand((unsigned) time(NULL));
    int random = rand();
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(-0.1, 0.1);
    
    // Create an Eigen vector with random data
    VectorXd randomVec;
    randomVec = VectorXd::Random(M); //random number generator from Eigen -1 t0 1
    /*
    for (int i = 0; i<N; ++i){
      // U(i) += 0.1 + (random % 1); //method 1 for random number
     //  U(i) = dist(gen);  // method 2 for random number in a range of -0.1 to 0.1
      // U(i) = i + 1;  //just filling the vector
    }
    */
    //return U;
    return randomVec;
}



VectorXcd fastforward_fft(int& N, VectorXd& X) {
    int Nh = N / 2 + 1;
    VectorXcd Xk(Nh);

    fftw_plan f = fftw_plan_dft_r2c_1d(N, X.data(), reinterpret_cast<fftw_complex*>(Xk.data()), FFTW_ESTIMATE);
    fftw_execute(f);
    fftw_destroy_plan(f);

    return Xk;
}

VectorXd fastbackward_fft(int& N, VectorXcd& Xk) {
    VectorXd Ux(N);

    // Use fftw_plan_dft_c2r_1d for complex-to-real transform
    fftw_plan b = fftw_plan_dft_c2r_1d(N, reinterpret_cast<fftw_complex*>((Xk).data()), Ux.data(), FFTW_ESTIMATE);
    fftw_execute(b);
    fftw_destroy_plan(b);

    Ux /= N;
    return Ux;
}

int main() {
    
    cout << "Welcome to starting example of fftw!!" <<endl;
    cout << "Great, it compiles on fedora!!" << endl;
   
   //Simulation parameters
    int p = 4;
    int M = pow(2,p);
    VectorXd U;
    VectorXcd Xk(M/2 + 1);
    VectorXd Ux(M);
   
   //function calls
    U = random_generator(M);
    Xk = fastforward_fft(M,U);
    Ux = fastbackward_fft(M,Xk);
   
   //outputs
    cout <<"Lets see the random vector U: "<< endl;
    cout << U <<endl;
    
    cout<<"Print out the complex vector output from fastforward_fft: "<<endl;
    cout<<Xk<<endl;

    cout <<" Lets compare the final out put with the initial random input: "<<endl;
    cout << "U-org" <<" | "<<"Ux"<<endl;
    for (int j=0; j<M; j++){
       cout << U(j) <<" | "<< Ux(j)<<endl;
    }
    return 0;
}

