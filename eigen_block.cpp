#include <iostream>
#include <Eigen/Dense>
//#include <print>

using namespace std;
using namespace Eigen;

/*
This example shows the usage of block operations
Block of size (p,q) starting at i,j
Dynamic size: matrix.block(i,j,p,q)
fixed size: matrix.block<p,q>(i,j); 

*/

int main(){
    int N = 4;
    int size = N*N;
    MatrixXf A(N,N);

    A<< 1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16;
println(A);
//extracting block from the given matrix : rvalues : read    
    cout <<"Block in the middle "<< endl;
    cout << A.block<2,2>(1,1)<<endl<<endl;

//inserting block into the given array

    Array22f m;
    m<<1,2,
        3,4;
    Array44f n;
    n = Array44f::Constant(0.6);
    cout<<n<<endl<<endl;
    
    n.block<2,2>(1,1) = m;

    cout << n<<endl<<endl;

    //Lets do advance stuff with blocks

    double* buffer_data = new double[1000];

    Map<Matrix<double,Dynamic,Dynamic>> matA(buffer_data,10,100);

    Ref<Matrix<double, Dynamic, Dynamic>> blockA(matA.block(0,0,3,3));

    blockA<<1,2,3,4,5,6,7,8,9;

        for (int i=0; i<blockA.rows(); ++i){
        for(int j=0; j<blockA.cols(); ++j){
            cout << blockA(i,j)<<"  ";
        }
        cout << endl;    


    for (int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            cout << matA(i,j)<<"  ";
        }
        cout << endl;    
    } 
    }    




return 0;
}