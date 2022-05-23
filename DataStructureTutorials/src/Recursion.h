#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

int LinearRecursion(int n);
void TreeRecursion(int n);


//tests
void LinearRecursionTest();
void TreeRecursionTest();

void funA(int n);


void funB(int n);

void IndirectRecursionTest();

int fun(int n);

void NestedRecursionTest();


float sumNaturalRecursion(int n);

float sumNaturalIterative(int n);

float sumNaturalEquation(int n);

void sumNaturalTest();

float factRecursion(int n);

float factIterative(int n);

void factTest();

void powTest();

double taylorSeriesRecursion(int x, int n);
void taylorSeriesTest();
double taylorSeriesHornerRuleIterative(int x, int n);
double taylorSeriesHornerRuleRecursion(int x, int n);

typedef float(*funcPtr)(int);
typedef double(*fibFuncPtr)(int);
typedef float(*powFuncPtr)(int, int);
typedef double(*taylorFuncPtr)(int, int);
typedef int(*nCrFuncPtr)(int, int);
typedef void(*tohFuncPtr)(int, int, int, int);
typedef std::string(*strFuncPtr)(std::string);
typedef bool(*palfuncPtr)(std::string);
typedef std::string(*d2bfuncPtr)(int);



void timeFunction(funcPtr, int n);
void timeFunction(powFuncPtr func, int m, int n);
void timeFunction(nCrFuncPtr func, int n, int r);
void timeFunction(taylorFuncPtr func, int x, int n);
void timeFunction(fibFuncPtr func,int n);
void timeFunction(tohFuncPtr func, int n, int A, int B, int C);
void timeFunction(strFuncPtr func, std::string input);
void timeFunction(palfuncPtr func, std::string input);
void timeFunction(d2bfuncPtr func, int value);





double fibonacciSeriesRecursion(int n);
double fibonacciSeriesMemoizationRecursion(int n);
double fibonacciSeriesIterative(int n);
void fibonacciSeriesTest();

int nCrIterative(int n, int r);
int nCrRecursion(int n, int r);
void nCrTest();

void TOH(int n, int A, int B, int C);
void TOHTest();

std::string stringReverseRecursion(std::string input);
std::string stringReverseIteration(std::string input);
void stringReverseTest();

bool isPalindromeRecursion(std::string input);
bool isPalindromeIterative(std::string input);
void isPalindromeTest();

std::string decimal2BinaryRecursion(int value);
std::string decimal2BinaryIterative(int value);
void decimal2BinaryTest();

template<class T>
int binarySearchRecursion(std::vector<T> array, T x, int leftIdx, int rightIdx);
void binarySearchTest();

template<class T>
void mergeSortRecursion(std::vector<T>* array, int leftIdx, int rightIdx);
template<class T>
void mergeHelper(std::vector<T>* array, int leftIdx, int mid, int rightIdx);

void mergeSortTest();