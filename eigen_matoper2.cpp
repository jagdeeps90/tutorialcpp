#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;


int main(){

	//dot [syntax= matA.dot(matB)]product between 2 vectors both should have the same size
         //dot product of 2 vecs: scalar ouput
         RowVector3d A(1,2,3); //either row or column vector
         RowVector3d B(4,5,6);
         cout<<"vector A: \n"<<A<<endl;
         cout<<"vector B: \n"<<B<<endl;
	 cout<<"The size of vector A: \n"<<A.size()<<endl;
         cout<<"The size of vector B: \n"<<B.size()<<endl; 
	 cout<<"The dot product of 2 vectors: \n"<<A.dot(B)<<endl;
         

         //cross product[syntax matA.cross(matB)]
         //cross of 2 vecs : vec output
         cout<<"Cross product of test Matrices is \n"<<A.cross(B)<<endl;

	//mat mat multiplication
        // syntax * operator
           Matrix2d AA;
           AA<<1,2,3,4;

         cout<<"mat mat multiplication of test Matrices is \n"<<AA*AA<<endl;


	//Transpose/Conjugate and Adjoint of a matrix
        // Create a MatrixXcf object
           MatrixXcf matrix; //complex matrix object c, f datatype
           matrix = MatrixXcf::Random(3,3);
           cout<<"Complex matrix is: \n"<<"["<<matrix<<"]"<<endl;
           cout<<"transpose of Complex matrix is: \n"<<"["<<matrix.transpose()<<"]"<<endl;    
 	   cout<<"Adjoint complex matrix is: \n"<<"["<<matrix.adjoint()<<"]"<<endl;
           cout<<"Conjugate complex matrix is: \n"<<"["<<matrix.conjugate()<<"]"<<endl;
return 0;


}
