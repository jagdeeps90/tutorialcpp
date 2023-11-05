#include <iostream>
#include <Eigen/Dense>

//This examples shows the conversion from mat to array
//to do certain operation suitable in array 
//for eg. element wise operations.
//WE DONT WANT a seperate MAT and arrray
using namespace std;
using namespace Eigen;
int main(){

	int N = 2;
	int size = N * N;

	double* fooA;
	double* fooB;
	double* foores;

	try {
	    fooA = new double[size];
	    fooB = new double[size];
	    foores = new double[size];
	}catch(bad_alloc b){
	cout <<"Bad allocation: "<<endl;
	}

	for(int i=0; i<size; i++){
		fooA[i] = 1.0; //intialize
                fooB[i] = 1.0;
		foores[i] = 1.0;
	}
	Map<Matrix<double,Dynamic,Dynamic>> A(fooA,N,N);
	Map<Matrix<double,Dynamic,Dynamic>> B(fooB,N,N);	
        Map<Matrix<double,Dynamic,Dynamic>> result(foores,N,N);

	A(0,0)=1; A(0,1)=2;
	A(1,0)=3;  A(1,1)=4;
        
	B << 5,6,
	     7,8;
	

	result = A * B;
	cout <<"--Matrix A x B: --\n"<< result<< "\n\n";

	result = A.array() * B.array();
	cout<<"--Array A x B --\n"<<result <<"\n\n";

	result = A.cwiseProduct(B);

	cout<<"--with cwise product --\n"<<result <<"\n\n";

	result = A.array() + 4;

	cout<<"--Array A + 4 --\n"<<result <<"\n\n";

	cout <<"fooA :"<<endl;
	for (int i=0; i<size;i++){
		cout << fooA[i];
	}
	cout <<endl;
	


delete [] fooA;
delete [] fooB;
delete [] foores;

return 0;

}
