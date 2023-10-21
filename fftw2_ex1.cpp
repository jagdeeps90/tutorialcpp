#include <fftw3.h>
#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>
#include <random>
using namespace std;
using namespace Eigen;

int main() {
    int p = 8;
    int N = pow(2,p);
    int Nh = N/2 + 1;
    srand((unsigned) time(NULL));
    int random = rand();
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(-0.1, 0.1);
    
    // Create an Eigen vector with random data
    RowVectorXd U = RowVectorXd::Random(N); //random number generator from Eigen -1 t0 1
    /*
    for (int i = 0; i<N; ++i){
      // U(i) += 0.1 + (random % 1); //method 1 for random number
     //  U(i) = dist(gen);  // method 2 for random number in a range of -0.1 to 0.1
      // U(i) = i + 1;  //just filling the vector
    }
    */
    cout<<U<<endl;
    VectorXcd Uk(Nh);
    VectorXd U_dum(N);
    // Plan a real-to-complex FFT and execute it
    fftw_plan forward_plan = fftw_plan_dft_r2c_1d(N, U.data(), reinterpret_cast<fftw_complex*>(Uk.data()), FFTW_ESTIMATE);
    fftw_execute(forward_plan);
    if (!forward_plan) {
    cerr << "Error planning the forward FFT." << endl;
    return 1; // Exit with an error code
}

    // Plan a complex-to-real IFFT and execute it to recover U_dum
    fftw_plan inverse_plan = fftw_plan_dft_c2r_1d(N, reinterpret_cast<fftw_complex*>(Uk.data()), U_dum.data(), FFTW_ESTIMATE);
    fftw_execute(inverse_plan);
    if (!inverse_plan) {
    cerr << "Error planning the inverse FFT." << endl;
    return 1; // Exit with an error code
}



    
    // Scale the result of the IFFT to match the original U
     U_dum /= N;

    // Clean up the plans
    fftw_destroy_plan(forward_plan);
    fftw_destroy_plan(inverse_plan);

    // Output should match the original U
    cout << "N\t U\t\t\t U_dum" << endl;
    for (int j = 0; j < N; j++) {
      cout << j<<"\t" <<U(j) << "\t\t" << U_dum(j) << endl;
    }  
    
    

    return 0;
}

