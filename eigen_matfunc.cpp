#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

/*
understanding the function and properties
*/
int main(){
	MatrixXd A(5,6);
 	cout<<" The matrix A has: "<<A.rows()<<"rows."<<endl;
	cout<<" The matrix A has: "<<A.cols()<<"cols."<<endl;
	cout<<" The matrix A has: "<<A.size()<<endl;
 	
	

	return 0;


}
