#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


int main(){
	//Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
	const int N = 4;
	Matrix<float, N, N> A;
        //filling up the 4x4 matrix
        for(int i=0; i<N; ++i){
           for(int j=0;j<N; ++j){
		A(j,i) = 1.0;
		}
	}	
	cout<<"The matrix A is :" <<endl<<A<<endl;
//vectors special case of matrix
	
	Matrix<float, 3, 1> vecA; //column vector
	Matrix<double, 1, 3> vecB; //row vector

	//initialize vector
	vecA.setZero(); 
	vecB.setConstant(1.0);

	cout<<"Column vector A :"<<endl<<vecA<<endl;
	cout<<"Row vector B :"<<endl<<vecB<<endl;
        
      //A default constructor is always available, never performs any dynamic memory allocation, and never initializes the matrix coefficients. 
 	Vector4d vecC;
	vecC = Vector4d::Random();

	VectorXd vecD;
        //linspace vector similar to python and matlab
	// here vector Linspaced(N,start,end)
	vecD = VectorXd::LinSpaced(10,0,1);

	cout<<"Random vector C :"<<endl<<vecC<<endl;
        cout<<"LinSpace vector D :"<<endl<<vecD<<endl;












return 0;
}

