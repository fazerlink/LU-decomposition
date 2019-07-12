#include <iostream>
#include "LU_decompozition.h"
#include "Print.h"
#include "inaccuracy.h"
int main()
{
	double  matrix_A[4][4] =
	{
	-5.35, -29.43, 25.50, 52.51,
	41.82, -26.60, 36.29, -40.16,
	-41.19, -1.26, 28.67, -56.82,
	-12.18, 41.95, 32.78, -12.52
	};
	double matrix_b[4] =
	{
		56.70,
		20.36,
		-60.05,
		-34.61
	};
	
	LU_decompozition(matrix_A, matrix_b, n);
	inaccuracy(n, matrix_A, matrix_b);
}