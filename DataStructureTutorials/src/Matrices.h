#pragma once
#include <iostream>

struct Matrix
{
	int* A;
	int n;
};

void InitMatrix(struct Matrix* m);

void Set(Matrix* m, int i, int j, int x);

int Get(Matrix m, int i, int j);

void Display(Matrix m);

void MatricesTest();
