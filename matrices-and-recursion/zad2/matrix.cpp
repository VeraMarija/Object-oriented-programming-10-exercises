#include "matrix.h"
#include<iostream>
#include<random>
#include<iomanip>

using namespace std;

Matrix interval_f(Matrix matrix) // matrica za generiranje elemenata u rasponu [a,b]
{
	float a, b;
	cout << "for generating matrix in interval" << endl;
	cout << "first enter a : "; cin >> a;
	cout << "now b :"; cin >> b;
	matrix.mtx = new float* [matrix.rows];
	for (int i = 0; i < matrix.rows;++i)
		matrix.mtx[i] = new float[matrix.cols];
	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.cols; j++)
		{
			matrix.mtx[i][j] = a + static_cast <float>  (rand()) / (static_cast <float> (RAND_MAX / (b - a)));
			cout << matrix.mtx[i][j] << " ";
		}
		cout << endl;
	} return matrix;
}
void output_f(Matrix matrix) //funkcija za ispisivanje matrice
{
	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.cols; j++)
		{
			cout << setprecision(5) << fixed;
			cout.width(15);
			cout << right << matrix.mtx[i][j] << " ";
		}
		cout << endl << endl;
	}
}
void transp_f(Matrix matrix) //funkcija za transponiranje matrica
{
	matrix.rows = 2;
	matrix.cols = 3;
	matrix = interval_f(matrix);
	cout << "transpose matrix is: " << endl << endl;
	for (int i = 0; i < matrix.cols; i++)
	{
		for (int j = 0; j < matrix.rows; j++)
			cout << matrix.mtx[j][i] << "  ";
		cout << endl;
	}
}
void mult_f(Matrix matrix1, Matrix matrix2) // funkcija za mnozenje matrica
{
	float sum = 0;
	for (int i = 0; i < matrix1.rows; i++)
	{
		for (int j = 0; j < matrix2.cols; j++)
		{
			sum = 0;
			for (int k = 0;k < matrix2.rows; ++k)
			{
				sum += matrix1.mtx[i][k] * matrix2.mtx[k][j];
			}
			cout << sum << " ";
		}	cout << endl;
	}
}
void subtr_f(Matrix matrix1, Matrix matrix2) // funkcija oduzimanje 
{
	for (int i = 0; i < matrix1.rows; i++)
	{
		for (int j = 0; j < matrix1.cols; j++)
			cout << matrix1.mtx[i][j] - matrix2.mtx[i][j] << " ";
		cout << endl;
	}
}
void sum_f(Matrix matrix1, Matrix matrix2) //funkcija zbrajanje
{
	for (int i = 0; i < matrix1.rows; i++)
	{
		for (int j = 0; j < matrix1.cols; j++)
			cout << matrix1.mtx[i][j] + matrix2.mtx[i][j] << " ";
		cout << endl;
	}
}
void del_f(Matrix matrix) // funkcija za brisanje 
{
	for (int i = 0; i < matrix.rows; i++)
		delete[] matrix.mtx[i];
	delete[] matrix.mtx;
}
Matrix input_f(Matrix matrix) // funkcija za unos matrice
{
	matrix.mtx = new float* [matrix.rows];
	for (int i = 0; i < matrix.rows;++i)
	{
		matrix.mtx[i] = new float[matrix.cols];
	}
	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.cols; j++)
			cin >> matrix.mtx[i][j];
		cout << endl;
	}
	return matrix;
}


