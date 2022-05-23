#ifndef ARRAYADT_H
#define ARRAYADT_H
#pragma once

#include <iostream>

struct Array
{
	int* A;
	int size;
	int length;
};


#endif

void ArrayADT_test();

void Display(Array arr);
void Append(Array* arr, int x);
void InsertAt(Array* arr, int index, int x);
int DeleteAt(Array* arr, int index);
void swap(int* x, int* y);
int LinearSearch(Array* arr, int key);
int LinearSearch_Transposition(Array* arr, int key);
int LinearSearch_MoveToHead(Array* arr, int key);
int BinarySearch(Array* arr, int key);
int BinarSearchRecursive(Array* arr, int key, int left_idx, int right_idx);

int Get(Array* arr, int index);

void Set(Array* arr, int index, int val);

int Max(Array* arr);

int Min(Array* arr);

int Sum(Array* arr);

int SumRecursive(Array* arr, int n);

int Average(Array* arr);

void Reverse(Array* arr);

void Reverse2(Array* arr);

void LeftShift(Array* arr);

void RightShift(Array* arr);

void LeftRotate(Array* arr);

void RightRotate(Array* arr);

void InsertSort(Array* arr, int x);

int isSorted(Array arr);

void RearrangePositiveNegative(Array* arr);

Array* Merge(Array* arr1, Array* arr2);

Array* Union(Array* arr1, Array* arr2);

Array* Intersection(Array* arr1, Array* arr2);

Array* Difference(Array* arr1, Array* arr2);
