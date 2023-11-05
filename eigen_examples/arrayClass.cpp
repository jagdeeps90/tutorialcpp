#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
//This example shows array class in Eigen
int main(){
	int N = 2;
	double* foo;
	try {
	      foo = new double[4];
	}catch (bad_alloc b){
		cout << "Error in main "<<endl;	
	}
	for (int i=0; i<4; i++){
		foo[i] = 5.0;	
	}
	Map<Array<double,Dynamic,Dynamic>> arrA(foo,N,N);
//assign values to array
	arrA(0,0) = 1.0;
	arrA(0,1) = 2.0;
	arrA(1,0) = 3.0;
	arrA(1,1) = arrA(0,0) + arrA(1,0);

//print values
	cout<< arrA<<endl<<endl;

	cout <<"Printing with comma-initializer"<<endl;

	arrA << 1.0,2.0,
	     3.0,4.0;

	cout <<arrA<<endl<<endl;

	
        



delete [] foo;
return 0;
}
