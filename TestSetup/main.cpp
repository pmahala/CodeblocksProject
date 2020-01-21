#include <iostream>
#include "MatrixOperations.h"

typedef MatrixOperations MATRIX;


using namespace std;

int main()
{
    MATRIX m1;

    //m1.setMatrixTo(MATRIX::toDiagonalArray, 3);
    //m1.displayMatrixOf(MATRIX::fromDiagonalArray);

    //m1.setMatrixTo(MATRIX::toLowerDiagonalRM,10);
    //m1.displayMatrixOf(MATRIX::fromLowerDiagonalRM);

    //m1.setMatrixTo(MATRIX::toLowerDiagonalCM,10);
    //m1.displayMatrixOf(MATRIX::fromLowerDiagonalCM);

    m1.setMatrixTo(MATRIX::toUpperDiagonalCM,10);
    m1.displayMatrixOf(MATRIX::fromUpperDiagonalCM);



    return 0;
}
