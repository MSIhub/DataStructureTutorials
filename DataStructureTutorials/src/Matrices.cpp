#include "Matrices.h"

void InitMatrix(struct Matrix* m)
{
	m->A = new int[m->n];
}

void Set(struct Matrix* m, int i, int j, int x)
{
	if (i == j)
		m->A[i - 1] = x;
}

int Get(struct Matrix m, int i, int j)
{
	if (i = j)
		return m.A[i - 1];
	else
		return 0;
}

void Display(struct Matrix m)
{
	int i, j;
	for (i = 0; i < m.n; i++)
	{
		for(j=0; j<m.n; j++)
		{
			if (i == j)
				std::cout << m.A[i] << " ";
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void MatricesTest()
{
	Matrix m;
	m.n = 4;
	InitMatrix(&m);
	Set(&m, 1, 1, 1);
	Set(&m, 2, 2, 2);
	Set(&m, 3, 3, 3);
	Set(&m, 4, 4, 4);
	Set(&m, 2, 4, 400);
	std::cout << Get(m, 2, 2) << std::endl; 
	Display(m);
}