#include "invertible.h"
void Invertible(const int n, double matrix[4][4], double matrix_end[4][4])
{

	double det;
	// <-------------trasponation--------------->
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_end[j][i] = matrix[i][j];


		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			std::cout << matrix_end[i][j] << " ";

		}
		std::cout << std::endl;

	}

	int p = 0;
	double x;
	for (int counter = 0; counter < n - 1; counter++)
	{
		for (int i = counter; i < n - 1; i++)
		{
			x = matrix[i + 1][counter] / matrix[counter][counter];
			for (int j = counter; j < n; j++)
			{
				matrix[i + 1][j] = matrix[i + 1][j] - x * matrix[counter][j];
			}
		}
	}
	det = matrix[0][0];
	for (int i = 1; i < n; i++)
	{
		det *= matrix[i][i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_end[i][j] = (matrix_end[i][j] / det) * 100000;
		}

	}


}