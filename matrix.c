#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

#define __DEBUG

#ifdef __DEBUG
#define __DP printf
#define __DEXE
#else
#define __DP 1 ? (void) 0 : printf
#define __DEXE 1 ? (void) 0 :
#endif

//現状正方行列以外は逆行列・行列式は考慮しない

Matrix* matrixInit(int x,int y)
{
  int i;
  Matrix* matrix;
  double** root;

  matrix = (Matrix *)malloc(sizeof(Matrix));

  if(matrix == NULL)
    return NULL;

  root = (double **)malloc(sizeof(double*)*y);

  if(root == NULL) {
    free(matrix);
    return NULL;
  }

  for(i=0;i<y;i++) {
    root[i] = (double *)malloc(sizeof(double)*x);
  }

  matrix->data = root;
  matrix->x = x;
  matrix->y = y;

  return matrix;
}

Matrix* matrixDestroy(Matrix* const matrix)
{
  if(matrix==NULL)
    return NULL;

  int i;
  for(i=0;i<matrix->y;i++) {
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);

  return NULL;
}

Matrix* matrixGetCopy(const Matrix* const src)
{
  Matrix* matrix;
  int i;

  matrix = matrixInit(src->x,src->y);

  if(matrix == NULL) {
    return NULL;
  }

  for(i=0;i<src->y;i++) {
    memcpy(matrix->data[i],src->data[i],sizeof(double)*src->x);
  }

  return matrix;
}

Matrix* matrixCalcMul(const Matrix* const matrixA,const Matrix* const matrixB)
{
  Matrix* matrixResult;

  double** data_result;
  double** data_a;
  double** data_b;

  int tmp_pos;
  int result_x;
  int result_y;

  double tmp;

  if(matrixA->y != matrixB->x ||
      matrixA == NULL ||
      matrixB == NULL)
  {
    return NULL;
  }

  matrixResult = matrixInit(matrixA->y,matrixB->x);

  if(matrixResult == NULL)
    return NULL;

  data_result = matrixResult->data;
  data_a = matrixA->data;
  data_b = matrixB->data;

  for(result_y=0;result_y<matrixA->y;result_y++) {
    for(result_x=0;result_x<matrixB->x;result_x++) {
      tmp = 0;
      for(tmp_pos=0;tmp_pos<matrixA->x;tmp_pos++) {
        tmp += data_a[result_y][tmp_pos] * data_b[tmp_pos][result_x];
      }

      data_result[result_y][result_x] = tmp;
    }
  }

  return matrixResult;
}

Matrix* matrixCalcScalaMul(const double value,const Matrix* const matrix)
{
  int x,y;
  double** data;
  double** data_result;
  Matrix* matrixResult;

  if(matrix == NULL)
    return NULL;

  matrixResult = matrixInit(matrix->x,matrix->y);

  if(matrixResult == NULL)
  {
    return NULL;
  }

  data = matrix->data;
  data_result = matrixResult->data;

  for(y=0;y<matrix->y;y++) {
    for(x=0;x<matrix->x;x++) {
      data_result[y][x] = value*data[y][x];
    }
  }

  return matrixResult;
}

double matrixCalcDeterminant(const Matrix* const matrix)
{
  double** data;
  double det;
  double buf;
  int i,x,y;

  Matrix* tmp;

  if(matrix == NULL)
    return 0;

  tmp = matrixGetCopy(matrix);

  if(tmp == NULL)
    return 0;

  data = tmp->data;

  for(x=0;x<matrix->x;x++) {
    for(y=0;y<matrix->y;y++) {

      //上三角行列のゼロにしなければならない場所
      //に入った時
      if(x<y) {

        //何で割ればゼロになるか求める
        buf = data[y][x] / data[x][x];
        __DP("buf = %lf\n",buf);

        //行基本変換
        //任意のゼロではない数を掛けあわせて足し算
        //（-の値をかけているとおいて、減算に変更）
        for(i=0;i<matrix->x;i++) {
          data[y][i] -= data[x][i] * buf;
        }
        __DEXE(matrixPrint(tmp));
      }
    }
  }

  __DEXE(matrixPrint(tmp));

  //対角成分を乗算
  for(i=0,det=1.0;i<matrix->x;i++)
    det *= data[i][i];

  data = NULL;
  tmp = matrixDestroy(tmp);

  return det;
}

Matrix* matrixGetInverse(const Matrix* const matrix)
{
  Matrix* matrixResult;

  if(matrix == NULL)
    return NULL;

  matrixResult = matrixInit(matrix->x,matrix->y);

  return matrixResult;
}

void matrixPrint(const Matrix* const matrix)
{
  int x,y;
  double** data;

  if(matrix==NULL) {
    printf("Matrix is NULL.\n");
    return;
  }

  data = matrix->data;

  printf("Matrix[%d][%d]\n",matrix->x,matrix->y);

  for(y=0;y<matrix->y;y++) {
    printf("(");
    for(x=0;x<matrix->x;x++) {
      printf(" %lf ",data[y][x]);
    }
    printf(")\n");
  }
}
