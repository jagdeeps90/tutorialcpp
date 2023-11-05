#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
int main(){

    int N = 1000;
    double* buffer;

    try{
        buffer = new double[N];
    }catch(bad_alloc b){
        cout<<"Problem in allocation: "<<endl;
    }

    Map<Matrix<double, Dynamic,Dynamic>> matA(buffer,10,100);

    Map<Matrix<double,Dynamic,Dynamic>> blockA(matA.data(),3,3);

    blockA << 1,2,3,
              4,5,6,
              7,8,9;

    for (int i=0; i<blockA.rows(); ++i){
        for(int j=0; j<blockA.cols(); ++j){
            cout << blockA(i,j)<<"  ";
        }
        cout << endl;    


    for (int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cout << matA(i,j)<<"  ";
        }
        cout << endl;    
    } 
    }   
    return 0;
}