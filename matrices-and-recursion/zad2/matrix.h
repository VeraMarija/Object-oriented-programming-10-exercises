#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<random>
#include<iomanip>
using namespace std;
typedef struct {
	float** mtx;
	int rows;
	int cols;
} Matrix;


Matrix interval_f(Matrix matrix);
void output_f(Matrix matrix);
void transp_f(Matrix matrix);
void mult_f(Matrix matrix1, Matrix matrix2);
void subtr_f(Matrix matrix1, Matrix matrix2);
void sum_f(Matrix matrix1, Matrix matrix2);
void del_f(Matrix matrix);
Matrix input_f(Matrix matrix);



#endif
