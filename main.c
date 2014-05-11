#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
  Matrix* matrixA;
  Matrix* matrixB;
  Matrix* matrixC;
  Matrix* tmp;

  matrixA = matrixInit(2,3);
  matrixB = matrixInit(3,2);
  matrixC = matrixInit(2,2);

  matrixA->data[0][0] = 2;
  matrixA->data[0][1] = 3;
  matrixA->data[1][0] = 4;
  matrixA->data[1][1] = 5;
  matrixA->data[2][0] = 6;
  matrixA->data[2][1] = 7;

  matrixB->data[0][0] = 8;
  matrixB->data[0][1] = 9;
  matrixB->data[0][2] = 10;
  matrixB->data[1][0] = 11;
  matrixB->data[1][1] = 12;
  matrixB->data[1][2] = 13;

  matrixC->data[0][0] = 11141;
  matrixC->data[0][1] = 149;
  matrixC->data[1][0] = 149;
  matrixC->data[1][1] = 4;

  tmp = matrixCalcMul(matrixA,matrixB);

  //matrixPrint(matrixA);
  //matrixPrint(matrixB);
  //matrixPrint(tmp);

  printf("det C = %lf\n",matrixCalcDeterminant(matrixC));

  tmp = matrixDestroy(tmp);
  matrixA = matrixDestroy(matrixA);
  matrixB = matrixDestroy(matrixB);
  matrixC = matrixDestroy(matrixC);

  return 0;
}
