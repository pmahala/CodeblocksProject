#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H


class MatrixOperations
{
    public:
        MatrixOperations();
        MatrixOperations(int size);
        ~MatrixOperations();



        void displayDiagonalMatrix();
        void setDiagonalMatrix();

    protected:

    private:
        int size;
        int* a;
        int getFromArray(int i, int j);
        void setToArray(int i, int value);
};

#endif // MATRIXOPERATIONS_H
