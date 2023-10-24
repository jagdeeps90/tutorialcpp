#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
int main(){
    double* buffer_data = new double[1000];

    Map < Matrix<double, Dynamic, Dynamic> > buffer(buffer_data,10,100);

    //Block is not a contigous memory

    Ref <Matrix <double, Dynamic, Dynamic> > foo(buffer.block(0,0,3,3));

    foo<< 1,2,3,4,5,6,7,8,9;

    //show regions

    for (int i=0; i<foo.rows(); ++i){
        for(int j=0; j<foo.cols(); ++j){
            cout << foo(i,j)<<"  ";
        }
        cout << endl;    
    }    

    for (int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            cout << buffer(i,j)<<"  ";
        }
        cout << endl;    
    } 



return 0;

}
