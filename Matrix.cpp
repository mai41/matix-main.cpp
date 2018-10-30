#include "matrix.h"
#include <iostream>

using namespace std;

// Takes an array of data and stores in matrix according
// to rows and columns
matrix::matrix(int r, int c, int num[])
{
 row = r;
 col = c;
 data = new int* [row];
 for (int i = 0; i < row; i++)
 data[i] = new int [col];
 for (int i = 0; i < row; i++)
 for (int j = 0; j < col; j++)
 data[i][j] = num[i * col + j];
 //ctor
}

matrix::matrix(int r, int c){
    row = r;
    col = c;
    data = new int*[row];
    for(int i=0; i<row; i++){
        data[i] = new int [col];
    }
}
//output matrix
ostream&operator<<(ostream &out,matrix &obj)
{
 for(int i = 0; i < obj.row; i++)
 {
 for(int j = 0; j < obj.col; j++)
 {
 out <<obj.data[i][j] << " ";
 }
 out << endl;
 }
 return out;
}

//input matrix
istream& operator>> (istream&in, matrix& mat)
{
 cout << "enter no. of rows:";
 in >> mat.row;
 cout << "enter no. of columns:";
 in >> mat.col;
 cout << "enter element of the matrix:" << endl;
 for (int i = 0; i < mat.row ; i++)
 {
 for (int j = 0; j < mat.col; j++)
 {
 in >> mat.data[i][j];
 }
 }
 return in;}


//returns true if 2 matrices are the same
bool matrix::operator==(const matrix& mat1)const{
    if ((mat1.row == row) && (mat1.col == col))
    {
        for(int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++)
            {
                if(mat1.data[i][j] != data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

//returns true if 2 matrices are not the same
bool matrix::operator!=(const matrix& mat1)const{
    if ((mat1.row == row) && (mat1.col == col))
    {
        for(int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++)
            {
                if(mat1.data[i][j] != data[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
    else
        return true;
}

//returns true if matrix is square
bool matrix::isSquare(const matrix& mat1)const{
    if(mat1.row == mat1.col)
    {
        return true;
    }
    else
        return false;
}

//returns true if matrix is square and symmetric
bool matrix::isSymetric(const matrix& mat1)const{
    if(mat1.row == mat1.col)               //make sure that matrix is square
    {
        for(int i = 0; i < mat1.row; i++)     //make sure that matrix is symmetric
            for(int j = 0; j < mat1.col; j++)
                if(mat1.data[i][j] != data[j][i])
                    return false;
        return true;
    }
    else
        return false;
}

//returns true if matrix is square and identity
bool matrix::isIdentity(const matrix& mat1)const{
    bool check;
    if(mat1.row == mat1.col)                 //make sure that matrix is square
    {
        for(int i = 0; i < mat1.row; i++)   //make sure that matrix is identity
        {
            for(int j = 0; j < mat1.col; j++)
            {
                if(i == j)
                {
                    if(mat1.data[i][j] == 1)
                    {
                        check = true;
                    }
                    else
                        return false;
                }
                else
                {
                    if(mat1.data[i][j] == 0)
                    {
                        check = true;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

//returns new matrix with the transpose
matrix matrix::transpose(const matrix& mat1)const{
    int newRow = mat1.row;
    int newCol = mat1.col;
    int x = 0;
    int *ptr;      //pointer to data in the matrix with the transposed
    ptr = new int [newCol * newRow];
    for (int i = 0; i < newRow; i++)
    {
        for (int j = 0; j < newCol; j++)
        {
            ptr[x] = mat1.data[i][j];
            x++;
        }
    }
    cout << "The transpose of matrix is: " << endl;
    return matrix(newCol,newRow,ptr);   //creating the transpose of the matrix
    delete[]ptr;

}

matrix::~matrix()
{
 //dtor
}
