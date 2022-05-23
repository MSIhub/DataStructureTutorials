#include "ArrayADT.h"

void ArrayADT_test()
{
	//struct Array arr;
	//printf("Enter size of the Array");
	//scanf("%d", &arr.size);
	//arr.A = (int*)malloc(arr.size*sizeof(int));
	//arr.length = 0;

	/*std::cout << "Enter size of the array: ";
	std::cin >> arr.size;
	arr.A = new int[arr.size];
	arr.length = 0;
	int n;
	std::cout << "Enter number of entries: ";
	std::cin >> n;
	if (n > arr.size)
	{
		std::cout << "Maximum number of entries cannot exceed the size of the array";
	}
	std::cout << "Enter elements" << ":\n";
	for (size_t i = 0; i < n; i++)
	{
		std::cout << "[" << i << "/" << n << "] : ";
		std::cin >> arr.A[i];
	}
	arr.length = n;*/

	struct Array arr = { new int[10]{2,3,4,5,6}, 10, 5 };
	Append(&arr, 19);
	//InsertAt(&arr, 4, 55);
	//InsertAt(&arr, 1, 114);
	//InsertAt(&arr, 0, 10000);
//	std::cout << DeleteAt(&arr, 0) << std::endl;
	Display(arr);
	std::cout << LinearSearch(&arr, 15) << std::endl;
	std::cout << BinarySearch(&arr, 6) << std::endl;
	std::cout <<  BinarSearchRecursive(&arr, 2, 0, arr.length - 1) << std::endl;

	/*Reverse(&arr);
	Display(arr);
	RightShift(&arr);
	Display(arr);
	LeftShift(&arr);
	Display(arr);
	LeftRotate(&arr);
	Display(arr);
	RightRotate(&arr);
	Display(arr);*/
	
	InsertSort(&arr, -2);
	/*Display(arr);
	InsertAt(&arr, 4, -55);
	Display(arr);
	std::cout << isSorted(arr) << std::endl;
	InsertAt(&arr, 6, -5);
	Display(arr);
	std::cout << arr.length << std::endl;*/
	//RearrangePositiveNegative(&arr);
	//Display(arr);

	struct Array arr1 = { new int[10]{2,6,10,15,25}, 10, 5};
	struct Array arr2 = { new int[15]{3,6,7,15,20}, 10, 5 };
	Display(arr1);
	Display(arr2);

	Array* arr3 = Union(&arr1, &arr2);
	Display(*arr3);
	Array* arr4 = Intersection(&arr1, &arr2);
	Display(*arr4);
	Array* arr5 = Difference(&arr1, &arr2);
	Display(*arr5);
}

void Display(Array arr)
{
	std::cout << "\nElements: ";
	for (size_t i = 0; i < arr.length; i++)
		std::cout << arr.A[i] << "\t";

	std::cout<< std::endl;
}


void Append(Array* arr, int x) 
{
	if (arr->length < arr->size)
		arr->A[arr->length++] = x;
}//O(1) Best and worst

void InsertAt(Array* arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length) 
	{
		for (i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];

		arr->A[index] = x;
		arr->length++;
	}
}//O(n) worst case O(1) best case

int DeleteAt(Array* arr, int index)
{
	int i; 
	if (index >= 0 && index <= arr->length)
	{
		int x = arr->A[index];
		for (i = index; i < arr->length - 1; i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
		return x;
	}
	return -1;
	
}//O(n) worst case O(1) best case

/*Linear search:
 Unique set of elements
 Search for Key.
 Start from start until the end to find the element
 */
int LinearSearch(Array* arr, int key)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i]) return i;
	}
	return -1;//if element is not found
}//O(n) worst and avg case and O(1) best case

/*Improvement to Linear search: 
1> TRANSPOSITION: Swap the element found a place before 
2> MOVE TO FRONT/HEAD: Swap the element found to the beginning of the array
*/

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int LinearSearch_Transposition(Array* arr, int key)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			swap(&arr->A[i], &arr->A[i - 1]);
			return i;
		}
	}
	return -1;//if element is not found
}//O(n) worst and avg case and O(1) best case


int LinearSearch_MoveToHead(Array* arr, int key)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			swap(&arr->A[i], &arr->A[0]);
			return i;
		}
	}
	return -1;//if element is not found
}//O(n) worst and avg case and O(1) best case

/*BINARY SEARCH
Condition: Array must be sorted
*/
int BinarySearch(Array* arr, int key)
{
	int left_idx = 0; 
	int right_idx = arr->length-1; 
	while (left_idx < right_idx)
	{
		int mid_idx = (left_idx + right_idx) / 2;
		if (arr->A[mid_idx] == key)
			return mid_idx;
		else if (key > arr->A[mid_idx])
			left_idx = mid_idx + 1;
		else
			right_idx = mid_idx - 1;
	}
	return -1;
}//O(1) best case -> O(log n) worst and avg case 

int BinarSearchRecursive(Array* arr, int key, int left_idx, int right_idx)
{
	if (left_idx <= right_idx)
	{
		int mid_idx = (left_idx + right_idx) / 2;
		if (arr->A[mid_idx] == key)
			return mid_idx;
		else if (key > arr->A[mid_idx])
			BinarSearchRecursive(arr, key, mid_idx + 1, right_idx);
		else
			BinarSearchRecursive(arr, key, left_idx, mid_idx - 1);
	}
	else
		return -1;
}

int Get(Array* arr, int index)
{
	bool isValidIndex = (index >= 0 && index < arr->length);
	if (isValidIndex)
		return arr->A[index];
	
	return -1;
}

void Set(Array* arr, int index, int val)
{
	bool isValidIndex = (index >= 0 && index < arr->length);
	if (isValidIndex)
		arr->A[index] = val;
}

int Max(Array* arr)
{
	int max = arr->A[0];
	for (int i = 1; i < arr->length; i++)
	{
		if (arr->A[i] > max)
			max = arr->A[i];
	}
	return max;
}

int Min(Array* arr)
{
	int min = arr->A[0];
	for (int i = 1; i < arr->length; i++)
	{
		if (arr->A[i] < min)
			min = arr->A[i];
	}
	return min;
}

int Sum(Array* arr)
{
	int sum = 0;
	for (int i = 0; i < arr->length; i++)
	{
			sum += arr->A[i];
	}
	return sum;
}

// call SumRecursive(&arr, arr->length-1 )
int SumRecursive(Array* arr, int n)
{
	if (n < 0)
		return 0;
	else
		return SumRecursive(arr, n - 1) + arr->A[n];
}

int Average(Array* arr)
{
	return Sum(arr)/arr->length;
}

void Reverse(Array* arr)
{
	int* B;
	int i, j;
	B = new int[arr->length];
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
		B[j] = arr->A[i];
	for (i = 0; i < arr->length; i++)
		arr->A[i] = B[i];
}

void Reverse2(Array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
		swap(&arr->A[i], &arr->A[j]);		
}

void LeftShift(Array* arr)
{
	for (int i = 0; i < arr->length-1; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}
	arr->A[arr->length - 1] = 0;
}

void RightShift(Array* arr)
{
	for (int i = arr->length - 1; i > 0; i--)
	{
		arr->A[i] = arr->A[i - 1];
	}
	arr->A[0] = 0;
}

void LeftRotate(Array* arr)
{
	int temp = arr->A[0];
	for (int i = 0; i < arr->length - 1; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}
	arr->A[arr->length - 1] = temp;
}

void RightRotate(Array* arr)
{
	int temp = arr->A[arr->length - 1];
	for (int i = arr->length - 1; i > 0; i--)
	{
		arr->A[i] = arr->A[i - 1];
	}
	arr->A[0] = temp;
}


void InsertSort(Array* arr, int x)
{
	int i = arr->length - 1;
	if (arr->length == arr->size)
		return;

	while (i >= 0 && arr->A[i] > x)
	{
		arr->A[i+1] = arr->A[i];//shift 
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;

}


int isSorted(Array arr) 
{
	for (int i = 0; i < arr.length - 1; i++) 
	{
		if (arr.A[i] > arr.A[i + 1])
			return 0;
	}
	return 1;
}

void RearrangePositiveNegative(Array *arr)
{
	int i, j;
	i = 0; 
	j = arr->length - 1;

	while (i < j)
	{
		if (arr->A[i] < 0 ) i++;
		if (arr->A[i] >= 0) j--;
		swap(&arr->A[i], &arr->A[j]);
	}
}

Array* Merge(Array* arr1, Array* arr2)// theta(m+n) // sorted arr1 and arr2 && output sorted arr3
{
	int total_length = arr1->length + arr2->length;
	Array* arr3 = new Array{ new int[total_length * 2] {}, int(total_length * 2), total_length };
	int i, j, k;
	i = 0, j = 0, k = 0;
	//sort and copy 
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}
	//copy the remaining elements
	for (int i2 = i; i2 < arr1->length; i2++)
		arr3->A[k++] = arr1->A[i2];

	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];

	return arr3;
}

Array* Union(Array* arr1, Array* arr2)
{
	int total_length = arr1->length + arr2->length;
	Array* arr3 = new Array{ new int[total_length * 2] {}, int(total_length * 2), total_length };
	int i, j, k;
	i = 0, j = 0, k = 0;
	//sort and copy 
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			arr3->A[k++] = arr2->A[j++];
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	//copy the remaining elements
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];

	arr3->length = k;
	return arr3;
}

Array* Intersection(Array* arr1, Array* arr2)
{
	int total_length = arr1->length + arr2->length;
	Array* arr3 = new Array{ new int[total_length * 2] {}, int(total_length * 2), total_length };
	int i, j, k;
	i = 0, j = 0, k = 0;
	//sort and copy 
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else if(arr1->A[i] == arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	arr3->length = k;
	return arr3;
}


Array* Difference(Array* arr1, Array* arr2)
{
	int total_length = arr1->length + arr2->length;
	Array* arr3 = new Array{ new int[total_length * 2] {}, int(total_length * 2), total_length };
	int i, j, k;
	i = 0, j = 0, k = 0;
	//sort and copy 
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else
		{
			i++; 
			j++;
		}
	}
	//copy the remaining elements in arr1
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];


	arr3->length = k;
	return arr3;
}
