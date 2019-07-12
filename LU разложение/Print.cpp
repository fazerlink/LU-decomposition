#include"Print.h"
void print_matrix(double matrix[4][4], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << "\t ";
		}
		std::cout << std::endl;

	}
	std::cout << std::endl;
}