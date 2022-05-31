#pragma once
#include <iostream>

void MatricesTest();

#pragma region DiagonalMatrix
class DiagonalMatrix
{
private:
	int n;
	int* A;
public:
	DiagonalMatrix(int n)
	{
		this->n = n;
		A = new int[n];
	}
	void set(int row, int col, int element);
	int get(int row, int col);
	void display();
	~DiagonalMatrix();

};
void DiagonalMatrixTest();
#pragma endregion

#pragma region LowerTriangularMatrix
class LowerTriangularMatrix
{
private:
	int n;
	int* A;
public:
	LowerTriangularMatrix()
	{
		this->n = 2;
		int numberofNonZeroElements = (n * ((n + 1) / 2));
		A = new int[numberofNonZeroElements];
	}
	LowerTriangularMatrix(int n)
	{
		this->n = n;
		int numberofNonZeroElements = (n * ((n + 1) / 2));
		//A = new int[numberofNonZeroElements];
		A = (int*)malloc(numberofNonZeroElements * sizeof(int));
	}
	void set(int row, int col, int element);
	int get(int row, int col);
	int getDimension() { return n; };
	void display();

	~LowerTriangularMatrix() { delete[] A; };

};
void LowerTriangularMatrixTest();
#pragma endregion


#pragma region UpperTriangularMatrix
class UpperTriangularMatrix
{
private:
	int n;
	int* A;
public:
	UpperTriangularMatrix()
	{
		this->n = 2;
		int numberofNonZeroElements = (n * ((n + 1) / 2));
		A = new int[numberofNonZeroElements];
	}
	UpperTriangularMatrix(int n)
	{
		this->n = n;
		int numberofNonZeroElements = (n * ((n + 1) / 2));
		A = new int[numberofNonZeroElements];
		
	}
	void set(int row, int col, int element);
	int get(int row, int col);
	int getDimension() { return n; };
	void display();

	~UpperTriangularMatrix() { delete[] A; };

};
void UpperTriangularMatrixTest();
#pragma endregion