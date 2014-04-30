#ifndef __MATRIX_H
#define __MATRIX_H

struct _Matrix {
  double** data;
  int x;
  int y;
};

typedef struct _Matrix Matrix;

Matrix* matrixInit(int x,int y);
Matrix* matrixDestroy(Matrix* const matrix);
Matrix* matrixCalcMul(const Matrix* const matrixA,const Matrix* const matrixB);
Matrix* matrixCalcScalaMul(const double value,const Matrix* const matrix);
double matrixCalcDeterminant(const Matrix* const matrix);
Matrix* matrixGetInverse(const Matrix* const matrix);

#endif
