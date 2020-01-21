#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

class MatrixOperations;

typedef int (MatrixOperations::*INTFUNC)(int,int);
typedef void (MatrixOperations::*VOIDFUNC)(int,int,int);

class MatrixOperations
{
    public:
        MatrixOperations();
        MatrixOperations(int size);
        ~MatrixOperations();


        //diagonal matrix funtions
        void displayMatrixOf(INTFUNC f);
        void setMatrixTo(VOIDFUNC f, int size);

        int getElement(INTFUNC from, int i, int j);
        void setElement(VOIDFUNC to,int i ,int j, int value);

        int fromDiagonalArray(int i, int j);
        void toDiagonalArray(int i, int j, int value);

        int fromLowerDiagonalRM(int i, int j);
        void toLowerDiagonalRM(int i, int j, int value);

        int fromLowerDiagonalCM(int i,int j);
        void toLowerDiagonalCM(int i, int j, int value);

        int fromUpperDiagonalRM(int i,int j);
        void toUpperDiagonalRM(int i,int j, int value);

        int fromUpperDiagonalCM(int i,int j);
        void toUpperDiagonalCM(int i, int j, int value);
    protected:

    private:
        int size;       //size of array
        int* a;
        int dimension; //size of matrix(n x n)

};



#endif // MATRIXOPERATIONS_H
