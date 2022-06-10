#pragma once

#include <iostream>
class Element
{
public:
	int row; 
	int col; 
	int val;
};

class SparseMatrix
{
private:
	int m;
	int n;
	int num;
	Element* ele;
public:
	SparseMatrix(int m, int n, int num)
	{
		this->m = m;
		this->n = n;
		this->num = num;
		ele = new Element[this->num];
	}
	~SparseMatrix()
	{
		delete[] ele;
	}

	SparseMatrix operator+(SparseMatrix& s);

	//Operator overloading 
	friend std::istream &operator >> (std::istream& is, SparseMatrix& s);
	friend std::ostream &operator << (std::ostream& os, SparseMatrix& s);
};




void sparseMatrixTest();


