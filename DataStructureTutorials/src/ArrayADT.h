#ifndef ARRAYADT_H
#define ARRAYADT_H
#pragma once

#include <iostream>

template<class T>
class Array
{
private:
	T* A;
	int size;
	int length;

	void swap(T* x, T* y);
public:
	Array()
	{
		size = 10;
		length = 0; 
		A = new T[size];
	}
	Array(int sz)
	{
		size = sz;
		length = 0; 
		A = new T[size];
	}
	~Array()
	{
		delete[] A;
	}

	void Display();
	void Append(T x);
	void InsertAt(int index, T x);
	T DeleteAt(int index);
	T LinearSearch(T key);
	T LinearSearch_Transposition(T key);
	T LinearSearch_MoveToHead(T key);
	T BinarySearch(T key);
	//int BinarSearchRecursive(int key, int left_idx, int right_idx);
	T Get(int index);
	void Set( int index, T val);
	T Max();
	T Min();
	T Sum();
	//int SumRecursive(int n);
	T Average();
	void Reverse();
	void Reverse2();
	void LeftShift();
	void RightShift();
	void LeftRotate();
	void RightRotate();
	void InsertSort(T x);
	bool isSorted();
	void RearrangePositiveNegative();
	Array* Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Intersection(Array arr2);
	Array* Difference(Array arr2);
	Array<T>* FindMissingElementSorted();
	Array<T>* FindMissingElementInt();
	Array<T>* FindDuplicateElementSorted();
	Array<T>* FindDuplicateElementInt();
	void FindPairForSum(T Sum);
	void FindPairForSumHash(T Sum);
	void FindPairForSumSorted(T Sum);

};

void ArrayADT_test();

#endif

