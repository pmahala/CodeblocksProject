#include "MatrixOperations.h"
#include <iostream>
using namespace std;

MatrixOperations::MatrixOperations()
{
    //ctor
    size = 3;
    a = new int[size];

}
MatrixOperations::MatrixOperations(int size)
{
    //ctor
    this->size = size;
    a = new int[size];


}


MatrixOperations::~MatrixOperations()
{
    //dtor
    delete[] a;
}

int MatrixOperations::getFromArray(int i, int j)
{
    if(i==j)
    {
        return a[i];
    }
    else
    {
        return 0;

    }
}
void MatrixOperations::setToArray(int i, int value)
{
    a[i] = value;
}


void MatrixOperations::displayDiagonalMatrix()
{
    for(int i{0}; i < size; i++)
    {
        for(int j{0}; j < size; j++)
        {
            cout << getFromArray(i,j) << "\t";
        }
        cout << endl;
    }

}

void MatrixOperations::setDiagonalMatrix()
{
    for(int i{0}; i < size; i++)
    {


            int value {};
            cout << "Enter value diagonal element " << i << " : ";
            cin >> value;
            setToArray(i,value);

    }

}
