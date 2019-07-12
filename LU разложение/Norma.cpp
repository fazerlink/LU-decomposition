#include"norma.h"
double norma(const int n, double matrix[4])
{
	double max = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(matrix[i]) > max)
		{
			max = abs(matrix[i]);
		}
	}
	std::cout << max << std::endl;
	return max;
}
double norma(const int n, double matrix[4][4])
{
	double max = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += abs(matrix[i][j]);
		}
		if (sum > max)
		{
			max = sum;
		}
		sum = 0;
	}
	std::cout << max << std::endl;
	return max;
}