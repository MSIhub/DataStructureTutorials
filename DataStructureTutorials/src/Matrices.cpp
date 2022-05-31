#include "Matrices.h"

void MatricesTest()
{
	//DiagonalMatrixTest();
	//LowerTriangularMatrixTest();
	UpperTriangularMatrixTest();
}

#pragma region Diagonal Matrix
void DiagonalMatrix::set(int row, int col, int element)
{
	if (row == col)
		A[row - 1] = element;
}

int DiagonalMatrix::get(int row, int col)
{
	if (row == col)
		return A[row - 1];
	else
		return 0;
}

void  DiagonalMatrix::display()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for(j=0; j< n; j++)
		{
			if (i == j)
				std::cout << A[i] << " ";
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

DiagonalMatrix::~DiagonalMatrix()
{
	int n = 0;
	delete [] A;
}

void DiagonalMatrixTest()
{
	DiagonalMatrix dm(4);
	dm.set(1, 1, 1);
	dm.set(2, 2, 2);
	dm.set(3, 3, 3);
	dm.set(4, 4, 4);
	dm.set(2, 4, 400);
	std::cout << dm.get(2, 2) << std::endl;
	dm.display();
}

#pragma endregion

#pragma region LowerTriangularMatrix
void LowerTriangularMatrix::set(int row, int col, int element)
{
	if (row >= col)
	{
		int indexValue = (row * ((row - 1) / 2)) + col - 1; //Row Major
		//int indexValue = n*(col -1) + (col -2)*(col -1)/2 +2+ row - col; //Column Major
		A[indexValue] = element;
	}
}

int LowerTriangularMatrix::get(int row, int col)
{
	if (row >= col)
	{
		int indexValue = (row * ((row - 1) / 2)) + col - 1; //Row Major
		//int indexValue = n*(col -1) + (col -2)*(col -1)/2 +2+ row - col; //Column Major
		return A[indexValue];
	}
	else
		return 0;
}

void  LowerTriangularMatrix::display()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i >= j)
			{
				int indexValue = (i * ((i - 1) / 2)) + j - 1; //Row Major
				//int indexValue = n*(j -1) + (j -2)*(j -1)/2 +2+ i - j; //Column Major
				std::cout << A[indexValue] << " ";
			}
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void LowerTriangularMatrixTest()
{
	int dimension = 0;
	int x = 0;
	std::cout << "Enter Dimension: ";
	std::cin >> dimension;
	LowerTriangularMatrix dm(dimension);
	std::cout << "Enter all elements: " << std::endl;
	for (int i = 1; i <= dimension; i++)
	{
		for (int j = 1; j <= dimension; j++)
		{
			std::cin >> x;
			dm.set(i, j, x);
		}
	}

	dm.display();
}

#pragma endregion

#pragma region UpperTriangularMatrix
void UpperTriangularMatrix::set(int row, int col, int element)
{
	if (row <= col)
	{
		int indexValue = (n * (row - 1) - ((row - 2) * (row - 1) / 2)) + (col - row);//Row major
		//int indexValue = col*(col-1)/2 + (row-1); //Column Major
		A[indexValue] = element;
	}
}

int UpperTriangularMatrix::get(int row, int col)
{
	if (row <= col)
	{
		int indexValue = (n * (row - 1) - ((row - 2) * (row - 1) / 2)) + (col - row);//Row major
		//int indexValue = col*(col-1)/2 + (row-1); //Column Major
		return A[indexValue];
	}
	else
		return 0;
}

void  UpperTriangularMatrix::display()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i <= j)
			{
				int indexValue = (n * (i - 1) - ((i - 2) * (i - 1) / 2)) + (j - i);//Row major
		//int indexValue = j*(j-1)/2 + (i-1); //Column Major
				std::cout << A[indexValue] << " ";
			}
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void UpperTriangularMatrixTest()
{
	int dimension = 0;
	int x = 0;
	std::cout << "Enter Dimension: ";
	std::cin >> dimension;
	UpperTriangularMatrix dm(dimension);
	std::cout << "Enter all elements: " << std::endl;
	for (int i = 1; i <= dimension; i++)
	{
		for (int j = 1; j <= dimension; j++)
		{
			std::cin >> x;
			dm.set(i, j, x);
		}
	}

	dm.display();
}

#pragma endregion


#pragma region Other types of matrices 
/*
1. Symmetric Matrix : M[i, j] = M[j, i]
	-> Implementation same as UpperTriangularMatrix or LowerTriangularMatrix
	-> Take anyone and while returing value instead of zero of the else case, return the same value of i,j == j, int

2. TriDiagonal Matrix: 
	Three diagonal: Main diagnol[i-j = 0], lower [i-j = 1] and upper [i-j = -1]
	i.e., mod(i-j) <= 1
	Number of elements needed = (3n-2)
	Diagnol wise access
	Index(A[i, j]):
	case1: if i-j = 1 -> indexVal = i-2
	case2: if i-j = 0 -> indexVal = (n-1) + (i-1)
	case2: if i-j = -1 -> indexVal = (2n-1) + (i-1)
3. Square Band Matrix:
	Similar to tridiagonal but with more than 3 diagonal distributed equal number of times from the main diagonal
4. TOEPLITZ MATRIX: M[i,j] = M[i-1, j-1]
	Elements in the diagonals are same 
	Number of elements needed for storage = (n)+ (n-1) // Store one row and one column
	Index(A[i, j]):
	case1: if i<=j -> indexVal = j-1
	case2: if i>j -> indexVal = n+(i-j-1)
*/

#pragma endregion