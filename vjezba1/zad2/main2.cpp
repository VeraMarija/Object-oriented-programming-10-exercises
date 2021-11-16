#include "matrix.h"
#include<iostream>
#include<random>
#include<iomanip>

using namespace std;

int main()
{
	Matrix matrix, matrix1, matrix2;
	cout << "Let's enter one matrix" << endl;
	cout << "how much rows do you want your matrix to have?" << endl;
	cin >> matrix.rows;
	cout << "how much columns do you want your matrix to have?" << endl;
	cin >> matrix.cols;
	matrix = input_f(matrix);
	output_f(matrix);
	del_f(matrix);
	matrix = interval_f(matrix);
	del_f(matrix);
	cout << "how much rows do you want 1.matrix to have?" << endl;
	cin >> matrix1.rows;
	cout << "how much columns do you want 1.matrix to have?" << endl;
	cin >> matrix1.cols;
	cout << "how much rows do you want 2.matrix to have?" << endl;
	cin >> matrix2.rows;
	cout << "how much columns do you want 2.matrix to have?" << endl;
	cin >> matrix2.cols;
	while ((matrix1.rows != matrix2.rows) || (matrix1.cols != matrix2.cols)) {
		cout << "error! matrices must have the same number of rows and cols!" << endl;
		cout << "how much rows do you want 1.matrix to have?" << endl;
		cin >> matrix1.rows;
		cout << "how much columns do you want 1.matrix to have?" << endl;
		cin >> matrix1.cols;
		cout << "how much rows do you want 2.matrix to have?" << endl;
		cin >> matrix2.rows;
		cout << "how much columns do you want 2.matrix to have?" << endl;
		cin >> matrix2.cols;
	}
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
	while (matrix1.cols != matrix2.rows)
	{
		cout << "your matrices can't be multiplied,enter again:" << endl;
		cout << "enter number of rows and cols for 1.matrix:" << endl;
		cin >> matrix1.rows >> matrix1.cols;
		cout << "enter number of rows and cols for 2.matrix:" << endl;
		cin >> matrix2.rows >> matrix2.cols;
	}
	cout << "enter matrix1=" << endl;
	matrix1 = input_f(matrix1);
	cout << "enter matrix2=" << endl;
	matrix2 = input_f(matrix2);
	mult_f(matrix1, matrix2);
	del_f(matrix1);
	del_f(matrix2);
	transp_f(matrix);
	del_f(matrix);
	return 0;
}
