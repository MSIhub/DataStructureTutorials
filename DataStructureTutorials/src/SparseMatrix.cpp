#include "SparseMatrix.h"

SparseMatrix SparseMatrix::operator+(SparseMatrix& s)
{
	int i = 0, j =0, k = 0; 
	if (m != s.m || n != s.n)
		return SparseMatrix(0,0,0);

	SparseMatrix* sum = new SparseMatrix(m, n, num + s.num);
	while (i < num && j < s.num)
	{
		if (ele[i].row < s.ele[j].row)
			sum->ele[k++] = ele[i++];
		else if (ele[i].col > s.ele[j].col)
			sum->ele[k++] = s.ele[j++];
		else
		{
			if (ele[i].col < s.ele[j].col)
				sum->ele[k++] = ele[i++];
			else if (ele[i].row > s.ele[k].row)
				sum->ele[k++] = s.ele[j++];
			else
			{
				sum->ele[k] = ele[i];
				sum->ele[k++].val = ele[i++].val + s.ele[j++].val;
			}
		}
	}

	for (; i < num; i++)
		sum->ele[k++] = ele[i];
	for (; j < s.num; j++)
		sum->ele[k++] = s.ele[j];

	sum->num = k;
	
	return *sum;

}

std::istream& operator >> (std::istream& is, SparseMatrix& s)
{
	std::cout << "Enter non-zero elements [row , col, val]:\n";
	for (int i = 0; i < s.num; i++)
		std::cin >> s.ele[i].row >> s.ele[i].col >> s.ele[i].val;

	return is;
}

std::ostream& operator << (std::ostream& os, SparseMatrix& s)
{
	int k = 0;
	for (int i = 0; i < s.m; i++)
	{
		for (int j = 0; j < s.n; j++)
		{
			if (s.ele[k].row == i && s.ele[k].col == j)
				std::cout << s.ele[k++].val << " ";
			else
				std::cout << "0 ";
		}
		std::cout << "\n";
	}

	return os;
}


void sparseMatrixTest()
{
	SparseMatrix s1(5, 5, 5);
	SparseMatrix s2(5, 5, 5);
	std::cin >> s1;
	std::cin >> s2;

	SparseMatrix sum = s1 + s2;
	std::cout << "First Matrix:\n" << s1;
	std::cout << "Second Matrix:\n" << s2;
	std::cout << "Sum Matrix:\n" << sum;


}

