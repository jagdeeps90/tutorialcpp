#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){

	MatrixXd matA(2,2);  
/*
MatrixXd represents an arbitrary sized Matrix in which every value is of type double.
*/
//Assignments:
//Method1 by element

        matA(0,0) = 3;
        matA(0,1) = 4;
	matA(1,0) = 2;
	matA(1,1) = 1;
	cout<<"element wise:\n "<<matA<<endl;
//Method 2: by operator
	matA<< 3,4,
	       2,1;
        cout <<" by operator:\n "<<matA <<endl;

//method by loop over elements
	for(int i=0; i<2;++i){
           for(int j=0;j<2;++j){
	       matA(j,i) = 0; //lets define 0 to all elements 	
               
		}
	}
        cout<<"Column major operations:\n "<<matA<<endl;
return 0;
}
