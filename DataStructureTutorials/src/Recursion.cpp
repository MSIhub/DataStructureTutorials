#include "Recursion.h"

#pragma region Types of Recursion

//Linear Recurssion
int LinearRecursion(int n)
{
	static int x = 0;
	if (n > 0)
	{
		x++;
		return LinearRecursion(n - 1) + x;
	}
	return 0;
}

void LinearRecursionTest()
{
	int r;
	r = LinearRecursion(5);
	printf("%d\n", r);

	r = LinearRecursion(5);
	printf("%d\n", r);
}

//Tree Recurssion
void TreeRecursion(int n)
{
	if (n>0)
	{
		printf("%d ", n);
		TreeRecursion(n-1);
		TreeRecursion(n-1);
	}
}

void TreeRecursionTest()
{
	TreeRecursion(3);
}

//Indirect Recursion 
void funA(int n)
{
	if (n> 0)
	{
		printf("%d ", n);
		funB(n-1);
	}
}

void funB(int n) 
{
	if (n > 0)
	{
		printf("%d ", n);
		funA(n/2);
	}
}

void IndirectRecursionTest() 
{
	funA(20);
}

// Nested Recursion 
int fun(int n)
{
	if (n > 100)
		return n - 10;
	return fun(fun(n + 11));
}

void NestedRecursionTest()
{
	int r;
	r = fun(99);
	printf("%d\n", r);
}
#pragma endregion

#pragma region Timer Function
void timeFunction(funcPtr func, int n)
{
	std::cout << std::fixed; //to show 
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "out: " << func(n) << std::setprecision(2) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "time: " << duration.count() << std::endl;
}

void timeFunction(powFuncPtr func, int m, int n)
{
	std::cout << std::fixed; //to show 
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "out: " << func(m, n) << std::setprecision(2) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "time: " << duration.count() << std::endl;
}

void timeFunction(taylorFuncPtr func, int x, int n)
{
	std::cout << std::fixed; //to show 
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "out: " << func(x, n) << std::setprecision(2) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "time: " << duration.count() << std::endl;
}


void timeFunction(fibFuncPtr func, int n)
{
	std::cout << std::fixed; //to show 
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "out: " << func(n) << std::setprecision(2) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "time: " << duration.count() << std::endl;
}

void timeFunction(nCrFuncPtr func, int n, int r)
{
	std::cout << std::fixed; //to show 
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "out: " << func(n, r) << std::setprecision(2) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "time: " << duration.count() << std::endl;
}

void timeFunction(tohFuncPtr func, int n, int A, int B, int C)
{
	std::cout << std::fixed; //to show 
	auto start = std::chrono::high_resolution_clock::now();
	func(n, A, B, C);
	//std::cout << "out: " << func(n, A, B, C) << std::setprecision(2) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "time: " << duration.count() << std::endl;
}


void timeFunction(strFuncPtr func, std::string input)
{
	std::cout << std::fixed; //to show 
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "out: " << func(input) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "time: " << duration.count() << std::endl;
}

void timeFunction(palfuncPtr func, std::string input)
{
	std::cout << std::fixed; //to show 
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "out: " << func(input) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "time: " << duration.count() << std::endl;
}

void timeFunction(d2bfuncPtr func, int value)
{
	std::cout << std::fixed; //to show 
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "out: " << func(value) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "time: " << duration.count() << std::endl;
}

#pragma endregion

#pragma region Sum of Natural Numbers
/**************************************************************************/
/*******************Sum of first n natural numbers ************************/
/**************************************************************************/
float sumNaturalRecursion(int n)
{
	if (n == 0)
		return 0;
	return float(sumNaturalRecursion(n - 1)+n);
}

float sumNaturalIterative(int n)
{
	int sum = 0;
	for(int i=1; i<=n; i++)
	{
		sum += i;
	}
	return float(sum);
}

float sumNaturalEquation(int n)
{
	return n * (float(n + 1) / 2.0f);
}

void sumNaturalTest()
{
	int n = 1500;
	timeFunction(sumNaturalRecursion, n);
	timeFunction(sumNaturalIterative, n);
	timeFunction(sumNaturalEquation, n);

}
#pragma endregion

#pragma region Factorial 
/**************************************************************************/
/******************* Factorial of n numbers ************************/
/**************************************************************************/
float factRecursion(int n)
{
	if (n < 0) {
		std::cout << "Value less than 0, this algorithm does not handle complex domain" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (n == 0 || n ==1)
		return 1;
	return (factRecursion(n - 1) * n);
}

float factIterative(int n)
{
	if (n < 0) {
		std::cout << "Value less than 0, this algorithm does not handle complex domain" << std::endl;
		exit(EXIT_FAILURE);
	}
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return float(result);
}

void factTest()
{
	int n = -1;
	timeFunction(factRecursion, n);
	timeFunction(factIterative, n);
}

#pragma endregion

#pragma region Power function
/**************************************************************************/
/******************* Power function [m power n] ************************/
/**************************************************************************/
float powRecursion(int m, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return powRecursion(m * m, n / 2);
	return m*powRecursion(m * m, (n - 1) / 2);
}

float powIterative(int m, int n)
{
	if (n == 0)
		return 1;

	float result = 1;
	if (n % 2 == 0)
	{
		n /= 2;
		m *= m;
	}
	else
	{
		result *= m;
		n = (n - 1) / 2;
		m = m * m;
	}
	
	for (int i = 1; i <= n; i++)
	{
		result *= m;
	}
	return result;
}

void powTest()
{
	int m = 2;
	int n = 31; // max value for 4 byte float 2^31
	timeFunction(powRecursion, m, n);
	timeFunction(powIterative, m, n);
}

#pragma endregion

#pragma region Taylor Series

/**************************************************************************/
/******************* Taylor series [e power x] ************************/
/**************************************************************************/
double taylorSeriesRecursion(int x, int n) // e power x for n terms // more n, higher accuracy
{
	if (n == 0)
		return 1.0;

	static double p = 1.0, f = 1.0;
	double result = taylorSeriesRecursion(x, n-1);
	p *= x;
	f *= n;
	return result + (p/f);
	
}// O(n^2) T 

double taylorSeriesHornerRuleIterative(int x, int n)
{
	double sum = 1.0;
	for (; n > 0; n--)
	{
		sum = 1 + (x*sum/n);
	}
	return sum;

}//O(n) T O(1) space

double taylorSeriesHornerRuleRecursion(int x, int n)
{
	static double sum = 1.0;
	if (n == 0)
		return sum;
	sum = 1 + ((double(x) / double(n)) * sum);
	return taylorSeriesHornerRuleRecursion(x, n-1);

}//O(n) Time and Space



void taylorSeriesTest()
{
	int x = 4;
	int n = 35; 
	timeFunction(taylorSeriesRecursion, x, n);
	timeFunction(taylorSeriesHornerRuleIterative, x, n);
	timeFunction(taylorSeriesHornerRuleRecursion, x, n);
}

#pragma endregion

#pragma region Fibonacci Series
/**************************************************************************/
/******************* Fibonacci Series ************************/
/**************************************************************************/

double fibonacciSeriesRecursion(int n)
{
	if (n <= 1)
		return n;
	return fibonacciSeriesRecursion(n - 2) + fibonacciSeriesRecursion(n - 1);
}//O(2^n) - Time

double fibonacciSeriesMemoizationRecursion(int n)
{
	if (n <= 1)
		return n;

	static std::vector<double> fibSeries;
	fibSeries.reserve(n);
	fibSeries.emplace_back(0);
	fibSeries.emplace_back(1);
	for (int i = 2; i <= n; i++)
	{
		fibSeries.emplace_back(-1);
	}

	for (int i = 2; i <= n; i++)
	{
		if (fibSeries.at(i - 2) == -1)
		{
			fibSeries[i - 2] = fibonacciSeriesMemoizationRecursion(i - 2);
		}
		if (fibSeries.at(i - 1) == -1)
		{
			fibSeries[i - 1] = fibonacciSeriesMemoizationRecursion(i - 1);
		}
		fibSeries[i] = fibSeries[i - 2] + fibSeries[i - 1];
	}

	return fibSeries.back();
}//O(n) - Time and Space


double fibonacciSeriesIterative(int n)
{
	if (n <= 1)
		return n;

		/*std::vector<double> fibSeries;
		fibSeries.reserve(n);
		fibSeries.emplace_back(0);
		fibSeries.emplace_back(1);
		for (int i = 2; i <= n; i++)
		{
			fibSeries.emplace_back(fibSeries.at(i - 2) + fibSeries.at(i-1));
			}
		return fibSeries.back();*/ //O(n) time and Space

	double term_prev2 = 0.0, term_prev = 1.0, term_curr;
	for (int i = 2; i <= n; i++)
	{
		term_curr = term_prev2 + term_prev;
		term_prev2 = term_prev;
		term_prev = term_curr;
	}
	return term_curr; // O(n) Time and Space
}

void fibonacciSeriesTest()
{
	int n = 6;
	timeFunction(fibonacciSeriesRecursion, n);
	timeFunction(fibonacciSeriesMemoizationRecursion, n);
	timeFunction(fibonacciSeriesIterative, n);
}
#pragma endregion

#pragma region Combination
/**************************************************************************/
/******************* Combination ************************/
/**************************************************************************/
int nCrIterative(int n, int r)//formulae
{
	int num = factIterative(n);
	int den = factIterative(r) * factIterative(n-r);
	return num / den;
}//O(3n) -> O(n) Time and O(1) Space

int nCrRecursion(int n, int r)//Pascal's triangle
{
	if (r > n)
		return 0;
	if (r == 0 || n == r)
		return 1;
	else
		return nCrRecursion(n - 1, r - 1) + nCrRecursion(n - 1, r);
}

void nCrTest()
{
	int n = 6; 
	int r = 3;
	timeFunction(nCrRecursion, n, r);
	timeFunction(nCrIterative, n, r);
}

#pragma endregion

#pragma region Tower of Hanoi
/**************************************************************************/
/******************* Towe of Hanoi ************************/
/**************************************************************************/
void TOH(int n, int A, int B, int C)//from using to
{
	if (n > 0)
	{
		TOH(n - 1, A, C, B);
		printf("(%d, %d)\n", A, C);
		TOH(n - 1, B, A, C);
	}
}

void TOHTest()
{
	timeFunction(TOH, 5, 1, 2, 3);
}

#pragma endregion

#pragma region String Reversal
std::string stringReverseRecursion(std::string input)
{
	if (input == "") { return ""; }
	int length = input.size();
	std::string out = { input[length - 1] };
	out += stringReverseRecursion(input.substr(0, length - 1));
	return out;
}

std::string stringReverseIteration(std::string input)
{
	if (input == "") { return ""; }
	std::string out;
	int length = input.size();
	for (int i = length - 1; i >= 0; i--)
	{
		out += input[i];
	}
	return out;
}


void stringReverseTest() 
{
	std::string input = "https://www.google.com/search?q=complexity+of+copying+a+string+in+c%2B%2B&oq=complexity+of+copying+a+string+in+c%2B%2B&aqs=chrome..69i57.11103j0j7&sourceid=chrome&ie=UTF-8";
	timeFunction(stringReverseRecursion,input) ;
	timeFunction(stringReverseIteration,input) ;
}
#pragma endregion

#pragma region String Palindrome
bool isPalindromeRecursion(std::string input)
{
	int strLen = input.size();
	if (strLen <= 1)
		return true;

	if (input[0] == input[strLen - 1])
		return isPalindromeRecursion(input.substr(1, strLen - 2));

	return false;
	
}

bool isPalindromeIterative(std::string input)
{
	int length = input.size();
	bool out = true;
	int left = 0, right = length -1 ;
	while (left < right)
	{
		out *=input[left] == input[right];
		left++;
		right--;
	}
	return out;
}

void isPalindromeTest()
{
	std::string input = "saippuakivikauppias";
	timeFunction(isPalindromeRecursion, input);
	timeFunction(isPalindromeIterative, input);
}
#pragma endregion

#pragma region Decimal2Binary
std::string decimal2BinaryRecursion(int value)
{
	static std::string result = {};
	if (value == 0) 	
	{
		return result;
	}
	result.insert(0, std::to_string(value % 2));
	return decimal2BinaryRecursion(value/2);
}

std::string decimal2BinaryIterative(int value)
{
	std::string result = {};
	int newValue = value;
	while (newValue > 0)
	{
		int rem = newValue % 2;
result.insert(0, std::to_string(rem));
newValue /= 2;
	}
	return result;

}

void decimal2BinaryTest()
{
	int input = 10555332;
	timeFunction(decimal2BinaryRecursion, input);
	timeFunction(decimal2BinaryIterative, input);
}
#pragma endregion

#pragma region Binary Search
template<class T>
int binarySearchRecursion(std::vector<T> array, T x, int leftIdx, int rightIdx)
{
	static bool isSorted = false;
	if (!isSorted)
	{
		std::sort(array.begin(), array.end()); // O(n log n) 
		isSorted = true;
	}
	if (leftIdx > rightIdx)
		return -1;

	int mid = (leftIdx + rightIdx) / 2;
	int midValue = array[mid];
	if (x == array[mid])
	{
		return mid;
	}

	if (x < array[mid])
	{
		return binarySearchRecursion(array, x, leftIdx, mid - 1);
	}

	return binarySearchRecursion(array, x, mid + 1, rightIdx);
}


void binarySearchTest()
{
	std::vector<int> array = { 1, 5, 8, 45, 88 };
	int value = 10;
	std::cout << binarySearchRecursion(array, value, 0, array.size() - 1) << std::endl;

	std::vector<float> array2 = { 1.2, 5.6, 8.4, 45.9, 88.8 };
	float value2 = 45.9;
	std::cout << binarySearchRecursion(array2, value2, 0, array2.size() - 1) << std::endl;

	std::vector<char> array3 = { 'a', 'b', 'c', 'd', 'e' };
	char value3 = 'e';
	std::cout << binarySearchRecursion(array3, value3, 0, array3.size() - 1) << std::endl;
}

#pragma endregion

#pragma region Merge sort
template<class T>
void mergeSortRecursion(std::vector<T>* array, int leftIdx, int rightIdx)
{
	if (leftIdx < rightIdx)
	{
		int	mid = (leftIdx + rightIdx) / 2;
		mergeSortRecursion(array, leftIdx, mid);
		mergeSortRecursion(array, mid + 1, rightIdx);
		mergeHelper(array, leftIdx, mid, rightIdx);
	}

}
template<class T>
void mergeHelper(std::vector<T>* array, int leftIdx, int mid, int rightIdx)
{
	std::vector<T> tempArray(rightIdx - leftIdx + 1, -1);

	// both sub array have values, then try and merge  them in sorted order
	int i = leftIdx, j = mid + 1, k = 0;
	while (i <= mid && j <= rightIdx)
	{
		if ((*array)[i] < (*array)[j])
		{
			tempArray[k] = (*array)[i];
			i++; k++;
		}
		else
		{
			tempArray[k] = (*array)[j];
			j++; k++;
		}
	}

	//Add rest of the left sub array to the temp array
	while (i <= mid)
	{
		tempArray[k] = (*array)[i];
		k++; i++;
	}
	//Add rest of the right sub array to the temparray
	while (j <= rightIdx)
	{
		tempArray[k] = (*array)[j];
		j++; k++;
	}
	
	for (i = leftIdx; i <= rightIdx; i++)
	{
		(*array)[i] = tempArray[i-leftIdx];
	}

}


void mergeSortTest()
{
	std::vector<int> array = {-888, -8, 2, 5, 5, -2, 8, -45, 88 };
	mergeSortRecursion(&array, 0, array.size() - 1);
	for (auto& o : array)
		std::cout << o << "\t";

	std::cout << "\n";


	std::vector<float> array2 = { 1.2, 5.6, 8.4, 45.9, 88.8 };
	mergeSortRecursion(&array2, 0, array2.size() - 1);
	for (auto& o : array2)
		std::cout << o << "\t";

	std::cout << "\n";
	

	std::vector<char> array3 = { 'a', 'd', 'e', 'b', 'c'};
	mergeSortRecursion(&array3, 0, array3.size() - 1);
	for (auto& o : array3)
		std::cout << o << "\t";

	std::cout << "\n";
}

#pragma endregion