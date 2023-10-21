#include <iostream>
#include <Eigen/Dense>

/*Specialised Block operation on matrix
C++ Eigen::Specialized Block Operations
Individual columns and rows are special cases of blocks.
Eigen provides methods to easily address them: 
.col() and .row().
*/

using namespace Eigen;
using namespace std;


int main(){
MatrixXf M(4,4); //dynamic matrix

M << 1,2,3,4,
    5,6,7,8,
    9,10,11,12,
    13,14,15,16;

//fixed
cout << "Here is the Matrix M: "<<endl<<M <<endl;
cout << "Extract 2nd row: "<<endl<<M.row(1) <<endl;
//operation on column then extract the modified column
cout<<"Extract column third: "<<endl<<M.col(2)<<endl;

cout<< "Modify the 3rd column = 3*col(0) :"<<endl;
M.col(2) = 3*M.col(0);

cout<<"Printing the modified matrix: "<<endl<<M<<endl;



//Corner-related operations
//ex1: top left p by q block
//example for both dynamic and fixed block operations
cout<<"Print top left corner: "<<endl<<M.topLeftCorner(3,3)<<endl;
cout<<"Print bottom left corner: "<<endl<<M.bottomLeftCorner(3,3)<<endl;
cout<<"Print top Right corner: "<<endl<<M.topRightCorner(3,3)<<endl;
cout<<"Print bottom Right corner: "<<endl<<M.bottomRightCorner(3,3)<<endl;
cout<<"top rows: "<<endl<<M.topRows(2)<<endl; //no. of rows from top
cout<<"bottom rows: "<<endl<<M.bottomRows(2)<<endl;
cout<<"left cols: "<<endl<<M.leftCols(2)<<endl;
cout<<"right cols: "<<endl<<M.rightCols(2)<<endl;
cout<<"middle cols: "<<endl<<M.middleCols(2,1)<<endl;
cout<<"middle rows: "<<endl<<M.middleRows(2,1)<<endl;
return 0;

}
