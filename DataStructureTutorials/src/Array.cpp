#include "Array.h"


void declartionTypes()
{
	//static array, in stack
	int A[5];
	int B[3] = {1,2,3};
	int C[10] = { 2,4,6 };
	int D[5] = { 0 };
	int E[] = {1,2, 3,4,5,6};
	for (int i = 0; i < 6; i++)
	{
		//std::cout << &A[i] << std::endl;
		//std::cout << i[A] << std::endl;
	//	std::cout << *(&E[0]+i) << std::endl;
		//printf("%u \n", &A[i]);
	}

	// Dynamic array, using heap memory
	int* p = new int[10];
	 //p =(int *) malloc(5*sizeof(int));
	delete []p;// release the heap memory
	
	 // static array cannot be resize to the same memory address 
	int original_size = 3;
	int resize = 4;
	int* F = new int[original_size];
	for (size_t i = 0; i < original_size; i++)
	{
		F[i] = i + 6;
	}
	resizeArray(&F, 3, 4);
	for (int i = 0; i < resize; i++) {
		std::cout << F[i] << std::endl;
	}
}

void resizeArray(int **p, int original_size, int resize)
{
	int* q = new int[resize];
	int j = 0;
	while (j < resize)
	{
		if (j < original_size)
		{
			*(q + j) = *(*(p) + j);
		}
		else
		{
			*(q + j) = 0;
		}
		j++;
	}
	for (int i = 0; i < resize; i++) {
		std::cout << q[i] << std::endl;
	}
	free(*(p));
	*(p) = q;
	q = nullptr;

}
void TwoDArrayDemo() 
{
	const int rows = 3;
	const int columns = 4;
	// Method 1: stack 	
	int A[rows][columns] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	//Method 2: stack (the pointers to each column) and heap
	int* B[rows];
	for (size_t i = 0; i < rows; i++)
	{
		i[B] = new int[columns];
	}

	//Method 3: purely in heap
	int** C;
	C = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		C[i] = new int[columns];
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			//printf("%d ", C[i][j]);
			printf("%d ", *(*(C+i)+j)); // ELEMENT ACCESS USING POINTER LOGIC
		}
		printf("\n");
	}
}



/* Representation of arays in compilers
2D arrays
 Two types are done ;
	 Row-Major mapping : a00, a01, a02, a03, a10, a11, a12, a13, a20, a21, a22, a23 [c/c++]
			A[m][n]
			Address(A[i][j]) = BaseAddress +  [i*n+j]*w;   w= no.of bytes for that datatype in that compiler
	 Column-major mapping : a00, a10, a20, a01, a11, a21, a02, a12, a22, a03, a13, a23
		 A[m][n]
		 Address(A[i][j) = BaseAddress + [j*m+i]*w; 

4D arrays
 Two types are done ;
   w= no.of bytes for that datatype in that compiler
	 Row-Major mapping :	A[d1][d2][d3][d4]
			Address(A[i1][i2][i3][i4]) = BaseAddress +  [i1*(d2*d3*d4) + i2*(d3*d4) + i3 *(d4) + i4]*w;
	 Column-major mapping : A[d1][d2][d3][d4]
		    Address(A[i1][i2][i3][i4]) = BaseAddress +  [i4*(d1*d2*d3) + i3*(d1*d2) + i2 *(d1) + i1]*w;

nD arrays
	 w= no.of bytes for that datatype in that compiler
	 Row-Major mapping :	A[d1][d2][d3][d4]....[dn]
			Address(A[i1][i2][i3][i4]) = BaseAddress +  Sum{p=1 to n}[(i_p)* product{q=p+1 to n}(dq)] * w; 
			//  O(n^2) [n(n-1)/2 multiplications]
			//  Horner's rule will reduce the complexitly to O(n)
	 Column-major mapping : A[d1][d2][d3][d4]....[dn]
			Address(A[i1][i2][i3][i4]) = BaseAddress +  Sum{p=n to 1}[(i_p)* product{q=p-1 to 1}(dq)] * w;

*/