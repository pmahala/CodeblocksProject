#include <iostream>
#include "MatrixOperations.h"

typedef MatrixOperations MATRIX;

using namespace std;

int main()
{
    MATRIX m1, m2(5);

    m1.setDiagonalMatrix();
    m1.displayDiagonalMatrix();

    m2.setDiagonalMatrix();
    m2.displayDiagonalMatrix();

    return 0;
}
