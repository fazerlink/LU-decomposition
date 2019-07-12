#include <iostream>
#include"Print.h"
#include "LU_decompozition.h"
using namespace std;

void LU_decompozition(double matrix_A[4][4], double matrix_b[4], const int n)
{
	double sum = 0;


	double x[4]
	{
		0,
		0,
		0,
		0
	};
	double y[4] =
	{
		0,
		0,
		0,
		0
	};

	double L[4][4] =
	{
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
	};
	double U[4][4] =
	{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
	};

	cout << "A" << endl;
	print_matrix(matrix_A, n);
	for (int i = 0; i < n; i++)
	{
		L[i][0] = matrix_A[i][0];
		U[0][i] = matrix_A[0][i] / L[0][0];
	}


	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i >= j)
			{
				sum = 0;
				for (int k = 0; k < j; k++)
					sum += L[i][k] * U[k][j];

				L[i][j] = matrix_A[i][j] - sum;
				cout << "L[" << i + 1 << "]" << "[" << j + 1 << "] =" << matrix_A[i][j] << "-" << sum << "=" << L[i][j] << endl;
			}
			else
			{
				sum = 0;
				for (int k = 0; k < i; k++)
					sum += L[i][k] * U[k][j];

				U[i][j] = (matrix_A[i][j] - sum) / L[i][i];
				cout << "U[" << i + 1 << "]" << "[" << j + 1 << "] = (" << matrix_A[i][j] << "-" << sum << ") /" << L[i][i] << endl;
				cout << endl;
			}
			cout << endl;
			cout << "\tL" << endl;
			print_matrix(L, n);
			cout << "\tU" << endl;
			print_matrix(U, n);
		}
	}

	y[0] = matrix_b[0] / L[0][0];
	cout << "y[1] = " << y[0] << endl;

	for (int i = 1; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{

			sum += L[i][j] * y[j];

		}
		y[i] = (matrix_b[i] - sum) / (L[i][i]);
		sum = 0;
		cout << "y[" << i + 1 << "] = " << y[i] << endl;
	}
	cout << endl;
	for (int i = 3; i > -1; i--)
	{
		sum = 0;
		for (int j = 3; j > -1; j--)
		{

			sum += U[i][j] * x[j];
		}
		x[i] = (y[i] - sum);
		sum = 0;
		cout << "x[" << i + 1 << "] = " << x[i] << endl;
	}
}