#pragma once

#include<iostream>
using namespace std;
class matrix
{
public:
    matrix(int r, int c, int num[]);
    matrix(int r, int c);
    friend ostream& operator<< (ostream&, matrix& );
    friend istream& operator>> (istream&, matrix& );


    bool   operator== (const matrix& mat1)const;
    bool   operator!= (const matrix& mat1)const;
    bool   isSquare   (const matrix& mat1)const;
    bool   isSymetric (const matrix& mat1)const;
    bool   isIdentity (const matrix& mat1)const;
    matrix transpose (const matrix& mat3)const;
    virtual ~matrix();
protected:
private:
    int row,col;
    int **data;
};
