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
  matrixB = matrixInit(4,4);
  matrixC = matrixInit(2,2);

  matrixA->data[0][0] = 2;
  matrixA->data[0][1] = 3;
  matrixA->data[1][0] = 4;
  matrixA->data[1][1] = 5;
  matrixA->data[2][0] = 6;
  matrixA->data[2][1] = 7;

  matrixB->data[0][0] = 1;
  matrixB->data[0][1] = 2;
  matrixB->data[0][2] = 0;
  matrixB->data[0][3] = -1;
  matrixB->data[1][0] = -1;
  matrixB->data[1][1] = 1;
  matrixB->data[1][2] = 2;
  matrixB->data[1][3] = 0;
  matrixB->data[2][0] = 2;
  matrixB->data[2][1] = 0;
  matrixB->data[2][2] = 1;
  matrixB->data[2][3] = 1;
  matrixB->data[3][0] = 1;
  matrixB->data[3][1] = -2;
  matrixB->data[3][2] = -1;
  matrixB->data[3][3] = 1;

  matrixC->data[0][0] = 11141;
  matrixC->data[0][1] = 149;
  matrixC->data[1][0] = 149;
  matrixC->data[1][1] = 4;

  //matrixPrint(matrixA);
  //matrixPrint(matrixB);
  //matrixPrint(tmp);

  printf("det C = %lf\n",matrixCalcDeterminant(matrixC));

  tmp = matrixGetInverse(matrixC);
  printf("matrixC Inverse\n");
  matrixPrint(tmp);

  tmp = matrixDestroy(tmp);
  matrixA = matrixDestroy(matrixA);
  matrixB = matrixDestroy(matrixB);
  matrixC = matrixDestroy(matrixC);

  return 0;
}
