#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

/*
Matrix operations in Eigen
Addition, substraction, scalar multiplication
scalar division, dot product, cross product
mat-mat multiplication, transpose/conjugate
Adjoint of matrix
*/
int main(){

//Addition
	Matrix2d mat1;
	mat1<< 1,2,3,4;
	
	MatrixXd mat2(2,2);
	mat2<<5,6,7,8;
        
        MatrixXd sum(2,2);
        sum.setZero();
	sum = mat1 + mat2;

	cout <<" The sum of 2 matrix is:\n"<<sum<<endl;
//Difference
	MatrixXd diff(2,2);
        diff.setZero();
        diff = mat2 - mat1;
        cout <<" The difference of 2 matrix is:\n"<<diff<<endl;

//scalar multiplication
        int S = 2;

	MatrixXd scalarM(2,2);
        scalarM = S*mat1;

	cout<<"Scalar 2 * mat1: \n" <<scalarM<<endl;

//scalar division
        MatrixXd divM(2,2);
        divM = mat1/S;
        cout<<"Division by scalar : \n"<<divM<<endl;


return 0;


}
