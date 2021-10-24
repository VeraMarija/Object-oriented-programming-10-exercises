#include<iostream>
#include<random>
#include<iomanip>
using namespace std;
typedef struct {
	float** mtx;
	int rows;
	int cols;
} Matrix;
Matrix interval_f(Matrix matrix) // matrica za generiranje elemenata u rasponu [a,b]
{	float a, b;
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
{	for (int i = 0; i < matrix.rows; i++)
	{	for (int j = 0; j < matrix.cols; j++)
		{	cout << setprecision(5) << fixed;
			cout.width(15);
			cout << right << matrix.mtx[i][j] << " ";
		}
		cout << endl << endl;
	}
}
void transp_f(Matrix matrix) //funkcija za transponiranje matrica
{	matrix.rows = 2;
	matrix.cols = 3;
	matrix=interval_f(matrix);
	cout << "transpose matrix is: " << endl << endl ;
	for (int i = 0; i < matrix.cols; i++)
	{	for (int j = 0; j < matrix.rows; j++)
			cout << matrix.mtx[j][i] << "  ";
		cout << endl;
	}
}
void mult_f(Matrix matrix1, Matrix matrix2) // funkcija za mnozenje matrica
{	float sum = 0;
	for (int i = 0; i < matrix1.rows; i++)
	{	for (int j = 0; j < matrix2.cols; j++)
		{	sum = 0;
			for(int k=0;k< matrix2.rows; ++k)
			{	sum += matrix1.mtx[i][k] * matrix2.mtx[k][j]; }
			cout << sum <<  " " ;
		}	cout << endl;
	}
}
void subtr_f(Matrix matrix1, Matrix matrix2) // funkcija oduzimanje 
{	for (int i = 0; i < matrix1.rows; i++)
	{	for (int j = 0; j < matrix1.cols; j++)
			cout << matrix1.mtx[i][j] - matrix2.mtx[i][j] << " ";
		cout << endl ; }
}
void sum_f(Matrix matrix1, Matrix matrix2) //funkcija zbrajanje
{	for (int i = 0; i < matrix1.rows; i++)
	{	for (int j = 0; j < matrix1.cols; j++)
			cout << matrix1.mtx[i][j] + matrix2.mtx[i][j] << " ";
		cout << endl ; }
}
void del_f(Matrix matrix) // funkcija za brisanje 
{	for (int i = 0; i < matrix.rows; i++)
		delete[] matrix.mtx[i];
	delete[] matrix.mtx;
}
Matrix input_f(Matrix matrix) // funkcija za unos matrice
{	matrix.mtx = new float* [matrix.rows];
	for (int i = 0; i < matrix.rows;++i)
	{	matrix.mtx[i] = new float[matrix.cols];  }
	for (int i = 0; i < matrix.rows; i++)
	{	for (int j = 0; j < matrix.cols; j++)
			cin >> matrix.mtx[i][j];
		cout << endl;
	}
	return matrix;
}
int main()
{	Matrix matrix, matrix1,matrix2;
cout << "Let's enter one matrix" << endl;
	cout << "how much rows do you want your matrix to have?" << endl;
	cin >> matrix.rows;
	cout << "how much columns do you want your matrix to have?" << endl;
	cin >> matrix.cols;
	matrix=input_f(matrix);
	output_f(matrix);
	del_f(matrix);
	matrix=interval_f(matrix); 
	del_f(matrix);
	cout << "how much rows do you want your matrices to have?" << endl;
	cin >> matrix1.rows;
	matrix2.rows = matrix1.rows;
	cout << "how much columns do you want your matrices to have?" << endl;
	cin >> matrix1.cols;
	matrix2.cols = matrix1.cols;
	cout << "enter matrix1=" << endl;
	matrix1 = input_f(matrix1);
	cout << "enter matrix2=" << endl;
	matrix2 = input_f(matrix2);
	cout << "matrix1 + matrix 2 =" << endl;
	sum_f(matrix1, matrix2);
	cout << endl << "matrix1 - matrix 2 =" << endl;
	subtr_f(matrix1, matrix2);
	del_f(matrix1);
	del_f(matrix2);
	cout << endl << "multiplying matrices" << endl;
	cout << "enter number of rows and cols for 1.matrix:" << endl;
	cin >> matrix1.rows >> matrix1.cols;
	cout << "enter number of rows and cols for 2.matrix:" << endl;
	cin >> matrix2.rows >> matrix2.cols;
	while(matrix1.cols!=matrix2.rows)
	{	cout << "your matrices can't be multiplied,enter again:" << endl;
		cout << "enter number of rows and cols for 1.matrix:" << endl;
		cin >> matrix1.rows >> matrix1.cols;
		cout << "enter number of rows and cols for 2.matrix:" << endl;
		cin >> matrix2.rows >> matrix2.cols; }
	cout << "enter matrix1=" << endl;
	matrix1 = input_f(matrix1);
	cout << "enter matrix2=" << endl;
	matrix2 = input_f(matrix2);
	mult_f(matrix1, matrix2);
	del_f(matrix1);
	del_f(matrix2);
	transp_f(matrix);
	del_f(matrix);
}



		
	
