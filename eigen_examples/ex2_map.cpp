#include <iostream>
#include <Eigen/Dense>



using namespace std;
using namespace Eigen;
int main(){

	//inital heap allocation
	double* foo_data = new double[9];
	
	for (int i=0; i<9; i++){
	    foo_data[i] = 5.0;
	}
	
	Map <Matrix<double, Dynamic, Dynamic> > foo(foo_data,3,3);
	
	foo(1,1) = 100;
	
	foo = 2* foo.array();
	cout << "foo :"<<endl<<foo<<endl;
	cout <<	"foo_data :"<<endl;

	for (int i = 0; i < 9; i++) {
    	std::cout << foo_data[i] << std::endl;
}

	delete[] foo_data;


return 0;
}
