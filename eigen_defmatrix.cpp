//compile with following
//g++ -std=c++17 -o eigen_defmatrix eigen_defmatrix.cpp -I /opt/homebrew/opt/Eigen/include/eigen3/

// -I library path of Eigen
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
using namespace std;
using namespace Eigen;

int main(){
           //Method 1:
           cout<<"Lets define 3 x 3 matrix of floats and set all elements to 0!"<<endl;
           cout <<"Matrix <type,n,n> name"<<endl;
           cout<<"1. First entry is variable type: for eg: int, float,double" <<endl;
           cout<<"2. Second entry is Matrix dimension n,n"<<endl;
           Matrix <float, 3,3> A;
           A.setZero();          
           cout<<"A = "<<"\n"<< A <<endl;

           //Method 2:
           cout<<"Eigen also has built-in type definitions"<<endl;
           cout<< "3f- size 3x3, f-float,if we want 4x4 int, then 4i"<<endl;
           Matrix3f A1;
           A1.setZero();
           cout<<"A1 ="<<"\n"<<A1<<endl;
           
           
           //initialization          
	   Matrix3f AA;
	   Matrix4d BB;
           
	   AA<< 1.0f, 0.0f, 0.0f,
	     0.0f, 1.0f, 0.0f,
	     0.0f, 0.0f, 1.0f;

	//initialization BB by accessing individual elements
        // overloaded parantheses operators
       // The below loop because Eigen stores matrices in column-major order by default
	for (int i = 0; i<=3; ++i) {
	  for (int j=0;j<=3;++j) {
              BB(j,i) = 0.0;
          }
        }
       //lets output some elements of AA and BB

       cout<< "AA: "<<"\n"<<AA(1,2)<<endl;

       //Some methods of setting the elements of the matrix:
        //intialize
        Matrix3f X;
        Matrix4d Y;
        Matrix3f Z;
        Matrix3f XX;

        X = Matrix3f::Random(); //set uniform random value [-1,1]
        cout<<"X: Random[-1,1]: "<<"\n"<<X<<endl;
       	Y = Matrix4d::Identity(); //set identity matrix
        cout<<"Y: identity matrix: "<<"\n"<<Y<<endl;
 	Z = Matrix3f::Zero(); //set elements to zero or Z.setZero()
        cout<<"Z: 0's"<<"\n"<<Z<<endl;
        XX = Matrix3f::Ones(); //all ones
        cout<<"XX: all ones"<<"\n"<<XX<<endl;
return 0;

}
