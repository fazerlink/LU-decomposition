#include "inaccuracy.h"
#include "invertible.h"
#include "norma.h"
void inaccuracy(int const n, double matrix_A[4][4], double matrix_b[4])
{
	double Del_d = 0.01;
	double Sig_d;
	double invertible_matrix[4][4];
	double A_copy[4][4] =
	{
	-5.35, -29.43, 25.50, 52.51,
	41.82, -26.60, 36.29, -40.16,
	-41.19, -1.26, 28.67, -56.82,
	-12.18, 41.95, 32.78, -12.52
	};
	Sig_d = Del_d / norma(n, matrix_b);
	std::cout << "Sig_d = " << Sig_d << std::endl;
	Invertible(n, matrix_A, invertible_matrix);
	std::cout << "matrix" << std::endl;
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << invertible_matrix[i][j] << " ";
		}
		cout << endl;
	}*/
	std::cout << "norma A = " << norma(n, A_copy);
	std::cout << "norma A_T =" << norma(n, invertible_matrix);
	std::cout << "del_x <= " << norma(n, invertible_matrix) << " * " << norma(n, A_copy) << " * " << Sig_d << "=" << norma(n, invertible_matrix) * norma(n, A_copy) * Sig_d;

}
