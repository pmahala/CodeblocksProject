#include "MatrixOperations.h"
#include <iostream>
#include <math.h>
using namespace std;


MatrixOperations::MatrixOperations(): size{0},a{nullptr}
{
    //ctor
    //size = 0;
    //a = nullptr;


}
MatrixOperations::MatrixOperations(int s): size{s}
{
    a = new int[size];
}


MatrixOperations::~MatrixOperations()
{
    //dtor
    delete[] a;
}




///////////////////FUCNTION POINTER SECTION///////////////////////////////////
int MatrixOperations::getElement(INTFUNC from, int i, int j)
{
    return (this->*from)(i,j);

}

void MatrixOperations::setElement(VOIDFUNC to,int i ,int j, int value)
{

    (this->*to)(i,j,value);
}




/////////////////////////////////DIAGONAL ARRAY OPERATIONS/////////////////////////////////////////////////
int MatrixOperations::fromDiagonalArray(int i, int j)
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
void MatrixOperations::toDiagonalArray(int i, int j, int value)
{
    a[i] = value;
}
//////////////////////////////////////////////////////////////////////

int MatrixOperations::fromLowerDiagonalRM(int i, int j)
{
    if(j > i)
        return 0;
    else
    {
        int sum{};
        for(int k{0};k<=i;k++)
        {
            sum += k;
        }
        return a[sum + j];

    }
}
void MatrixOperations::toLowerDiagonalRM(int i, int j, int value)
{
    int sum {};
    for(int k{0};k<=i;k++)
    {
        sum += k;
    }
    a[sum + j] = value;

}
///////////////////////////////////////////////////////////////////

void MatrixOperations::toLowerDiagonalCM(int i, int j, int value)
{
    int sumLimit {j};
    int num{4};
    int sum{0};
    for(int k{0};k<sumLimit;k++)
    {
        sum += num;
        num--;
    }
    a[sum + (i-j)] = value;

}
int MatrixOperations::fromLowerDiagonalCM(int i, int j)
{
    if(j > i)
        return 0;
    else
    {
        int sumLimit {j};
        int num{4};
        int sum{0};
        for(int k{0};k<sumLimit;k++)
        {
            sum += num;
            num--;
        }
        return a[sum + (i-j)];

    }
}
///////////////////////////////////////////////////////

int MatrixOperations::fromUpperDiagonalRM(int i,int j)
{
    if(j < i)
    {
        return 0;
    }
    else
    {
        int Offset{0};
        int num{3};
        for(int k{1};k<=i;k++)
        {
            Offset+=num;
            num--;
            if(k == 1)
            {
                num++;
            }
        }
        return a[Offset + j];
    }
}
void MatrixOperations::toUpperDiagonalRM(int i,int j, int value)
{
    int Offset{0};
    int num{3};
    for(int k{1};k<=i;k++)
    {
        Offset+=num;
        num--;
        if(k == 1)
        {
            num++;
        }
    }
    a[Offset + j] = value;
}

int MatrixOperations::fromUpperDiagonalCM(int i,int j)
{
    if(j < i)
    {
        return 0;
    }
    int Offset{0};
    int num{1};
    for(int k{1}; k <= j; k++)
    {
        Offset += num;
        num++;
    }
    return a[Offset + i];

}
void MatrixOperations::toUpperDiagonalCM(int i, int j, int value)
{

    int Offset{0};
    int num{1};
    for(int k{1}; k <= j; k++)
    {
        Offset += num;
        num++;
    }
    a[Offset + i] = value;
}

///////////////////////////////////////////////////////////////////
void MatrixOperations::displayMatrixOf(INTFUNC f)
{
    for(int i{0}; i < dimension; i++)
    {
        for(int j{0}; j < dimension; j++)
        {
            cout << getElement(f,i,j) << "\t";
        }
        cout << endl;
    }

}

void MatrixOperations::setMatrixTo(VOIDFUNC f,int size)
{
    delete[] a;
    a = new int[size];
    this->size = size;

    cout << "Hello there!!" << endl;


    if(f == &MatrixOperations::toDiagonalArray)
    {
        dimension = size;
        for(int i{0}; i < dimension; i++)
        {

            int value {};
            cout << "Enter value diagonal element " << i << " : ";
            cin >> value;
            setElement(f,i,i,value);
        }
    }

    else if(f == &MatrixOperations::toLowerDiagonalRM)
    {
        int n {};
        n = (sqrt(8 * size + 1) - 1)/2;

        cout << "\nN is " << n;
        dimension = n;

        for(int i{0};i < n; i++)
        {
            for(int j{0}; j <= i; j++)
            {
                int value{};
                cout << "Enter value for element (" << i << " ," << j <<") :";
                cin >> value;
                setElement(f,i,j,value);
            }
        }

    }
    else if(f == &MatrixOperations::toLowerDiagonalCM)
    {
        int n{};
        n = (sqrt(8 * size + 1) - 1)/2;
        dimension = n;
        cout << "\nN is " << n;
        for(int j{0}; j < n; j++)
        {
            for(int i=j;i < n; i++)
            {
                int value{};
                cout << "Enter value for element (" << i << " ," << j <<") :";
                cin >> value;
                setElement(f,i,j,value);
            }
        }


    }
    else if(f == &MatrixOperations::toUpperDiagonalRM)
    {
        int n{};
        n = (sqrt(8 * size + 1) - 1)/2;
        dimension = n;

        for(int i{0}; i < n; i++)
        {
            for(int j{i}; j < n; j++)
            {
                int value{};
                cout << "Enter value for element (" << i << " ," << j <<") :";
                cin >> value;
                setElement(f,i,j,value);
            }
        }

    }
    else if(f == &MatrixOperations::toUpperDiagonalCM)
    {
        int n{};
        n = (sqrt(8 * size + 1) - 1)/2;
        dimension = n;

        for(int j{0}; j < n; j++)
        {
            for(int i{0}; i <= j; i++)
            {
                int value{};
                cout << "Enter value for element (" << i << " ," << j <<") :";
                cin >> value;
                setElement(f,i,j,value);
            }
        }

    }






}


///////////////////////////////////////////////////////////////////////////////




