#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;
/*
C++ Eigen::Matrix class
Matrix<Datatype, Number of Rows, Number of Columns>
Coefficients Data-type: Based on our requirement, 
the data type of coefficients need to be specified, 
For example, if we want a matrix containing double data-type we specify double here.
Number of Rows:  Here we specify the number of rows as known at compile time.
Number of Columns:  Here we specify the number of columns as known
at compile time.

Eigen allows us to create matrices whose Number of rows and columns are not known at 
compile time by handling them as a run-time variable. 
This can be achieved using the keyword Dynamic in place of Number of Rows and Number of Columns.

Matrix<Data-type,Dynamic,Dynamic>
*/

/*
Vector is a special case of matrix which has either single row or single column
Matrix<float , 1 , Number of Columns>   will define a Column vector.
Matrix<float, Number of Rows,1>       will define a Row vector.
*/

/*
predef in eigen: square mat: MatrixNf
columnvector VectorNf
rowvector  RowVectorNf
*/
int main(){
        //colum vector 
	Matrix<float, 1, 10> matA;
        matA.setZero();
	cout<<"matA is now: \n"<<matA<<endl;
        //row vector

	Matrix<float, 10, 1> matB;
        matB.setZero();
        cout<<"matB is now: \n"<<matB<<endl;
        
        Vector3f B;
        B.setZero();
        cout<<"B is now: \n"<<B<<endl;

}


