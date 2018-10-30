                                         
#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {1,0,0,0,1,0,0,0,1};
    int data3 [] = {1,2,4,2,3,5,4,5,5};
    matrix mat1(4, 2, data1);      //creating matrix no.1
    matrix mat2(3, 3, data2);      //creating matrix no.2
    matrix mat3(3, 3, data3);      //creating matrix no.3
    cin >> mat1;            //input data for matrix 1
    cout << endl;
    cout << "Matrix1: " << endl << mat1 << endl;
    cout << "Matrix2: " << endl << mat2 << endl;


    bool check1 = (mat2 == mat3);
    bool check2 = (mat2 != mat3);
    cout << "The boolean of 2 matrices to be identical= ";
    cout << check1 <<endl;
    cout << "The boolean of 2 matrices to be not identical= ";
    cout << check2 << endl;
    cout << "The boolean of a matrix to be square= ";
    cout << mat2.isSquare(mat2) << endl;
    cout << "The boolean of a matrix to be identity= ";
    cout << mat2.isIdentity(mat2) << endl;
    cout << "The boolean of a matrix to be symmetric= ";
    cout << mat3.isSymetric(mat3) << endl;
    cout << endl;
    mat1 = mat1.transpose(mat1);
    cout << mat1 << endl;
    system("pause");

    return 0;
}
