#include "ArrayADT.h"

template<class T>
void Array<T>::Display()
{
	std::cout << "\nElements: ";
	for (size_t i = 0; i < length; i++)
		std::cout << A[i] << "\t";

	std::cout<< std::endl;
}

template<class T>
void Array<T>::Append(T x) 
{
	if (length < size)
		A[length++] = x;
}//O(1) Best and worst

template<class T>
void Array<T>::InsertAt(int index, T x)
{
	int i;
	if (index >= 0 && index <= length) 
	{
		for (i = length; i > index; i--)
			A[i] = A[i - 1];

		A[index] = x;
		length++;
	}
}//O(n) worst case O(1) best case

template<class T>
T Array<T>::DeleteAt(int index)
{
	int i; 
	if (index >= 0 && index <= length)
	{
		int x = A[index];
		for (i = index; i < length - 1; i++)
			A[i] = A[i + 1];
		length--;
		return x;
	}
	return -1;
	
}//O(n) worst case O(1) best case

/*Linear search:
 Unique set of elements
 Search for Key.
 Start from start until the end to find the element
 */
template<class T>
T Array<T>::LinearSearch(T key)
{
	for (int i = 0; i < length; i++)
	{
		if (key == A[i]) return i;
	}
	return -1;//if element is not found
}//O(n) worst and avg case and O(1) best case

/*Improvement to Linear search: 
1> TRANSPOSITION: Swap the element found a place before 
2> MOVE TO FRONT/HEAD: Swap the element found to the beginning of the array
*/
template<class T>
void Array<T>::swap(T* x, T* y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}

template<class T>
T Array<T>::LinearSearch_Transposition(T key)
{
	for (int i = 0; i < length; i++)
	{
		if (key == A[i])
		{
			swap(&A[i], &A[i - 1]);
			return i;
		}
	}
	return -1;//if element is not found
}//O(n) worst and avg case and O(1) best case

template<class T>
T Array<T>::LinearSearch_MoveToHead(T key)
{
	for (int i = 0; i < length; i++)
	{
		if (key == A[i])
		{
			swap(&A[i], &A[0]);
			return i;
		}
	}
	return -1;//if element is not found
}//O(n) worst and avg case and O(1) best case

/*BINARY SEARCH
Condition: Array must be sorted
*/
template<class T>
T Array<T>::BinarySearch(T key)
{
	int left_idx = 0; 
	int right_idx = length-1; 
	while (left_idx < right_idx)
	{
		int mid_idx = (left_idx + right_idx) / 2;
		if (A[mid_idx] == key)
			return mid_idx;
		else if (key > A[mid_idx])
			left_idx = mid_idx + 1;
		else
			right_idx = mid_idx - 1;
	}
	return -1;
}//O(1) best case -> O(log n) worst and avg case 

//int BinarSearchRecursive(Array* arr, int key, int left_idx, int right_idx)
//{
//	if (left_idx <= right_idx)
//	{
//		int mid_idx = (left_idx + right_idx) / 2;
//		if (arr->A[mid_idx] == key)
//			return mid_idx;
//		else if (key > arr->A[mid_idx])
//			BinarSearchRecursive(arr, key, mid_idx + 1, right_idx);
//		else
//			BinarSearchRecursive(arr, key, left_idx, mid_idx - 1);
//	}
//	else
//		return -1;
//}
template<class T>
T Array<T>::Get(int index)
{
	bool isValidIndex = (index >= 0 && index < length);
	if (isValidIndex)
		return A[index];
	
	return -1;
}

template<class T>
void Array<T>::Set(int index, T val)
{
	bool isValidIndex = (index >= 0 && index < length);
	if (isValidIndex)
		A[index] = val;
}

template<class T>
T Array<T>::Max()
{
	T max = A[0];
	for (int i = 1; i < length; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

template<class T>
T Array<T>::Min()
{
	T min = A[0];
	for (int i = 1; i < length; i++)
	{
		if (A[i] < min)
			min = A[i];
	}
	return min;
}

template<class T>
T Array<T>::Sum()
{
	T sum = 0;
	for (int i = 0; i < length; i++)
			sum += A[i];
	
	return sum;
}

// call SumRecursive(&arr, arr->length-1 )
//int SumRecursive(Array* arr, int n)
//{
//	if (n < 0)
//		return 0;
//	else
//		return SumRecursive(arr, n - 1) + arr->A[n];
//}
template<class T>
T Array<T>::Average()
{
	return Array::Sum()/length;
}

template<class T>
void Array<T>::Reverse()
{	
	int i, j;
	T* B = new T[length];
	for (i = length - 1, j = 0; i >= 0; i--, j++)
		B[j] = A[i];
	for (i = 0; i < length; i++)
		A[i] = B[i];
}

template<class T>
void Array<T>::Reverse2()
{
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--)
		swap(&A[i], &A[j]);		
}

template<class T>
void Array<T>::LeftShift()
{
	for (int i = 0; i < length-1; i++)
	{
		A[i] = A[i + 1];
	}
	A[length - 1] = 0;
}

template<class T>
void Array<T>::RightShift()
{
	for (int i = length - 1; i > 0; i--)
	{
		A[i] = A[i - 1];
	}
	A[0] = 0;
}
template<class T>
void Array<T>::LeftRotate()
{
	T temp = A[0];
	for (int i = 0; i < length - 1; i++)
	{
		A[i] = A[i + 1];
	}
	A[length - 1] = temp;
}

template<class T>
void Array<T>::RightRotate()
{
	T temp = A[length - 1];
	for (int i = length - 1; i > 0; i--)
	{
		A[i] = A[i - 1];
	}
	A[0] = temp;
}

template<class T>
void Array<T>::InsertSort(T x)
{
	int i = length - 1;
	if (length == size)
		return;

	while (i >= 0 && A[i] > x)
	{
		A[i+1] = A[i];//shift 
		i--;
	}
	A[i + 1] = x;
	length++;

}

template<class T>
bool Array<T>::isSorted()
{
	for (int i = 0; i < length - 1; i++) 
	{
		if (A[i] > A[i + 1])
			return false;
	}
	return true;
}

template<class T>
void Array<T>::RearrangePositiveNegative()
{
	int i, j;
	i = 0; 
	j = length - 1;

	while (i < j)
	{
		if (A[i] < 0 ) i++;
		if (A[i] >= 0) j--;
		swap(&A[i], &A[j]);
	}
}

template<class T>
Array<T>* Array<T>::Merge(Array<T> arr2)// theta(m+n) // sorted arr1 and arr2 && output sorted arr3
{
	int total_length = (length + arr2.length)*1.5;
	Array<T>* arr3 = new Array<T>(total_length);
	int i, j, k;
	i = 0, j = 0, k = 0;
	//sort and copy 
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else
			arr3->A[k++] = arr2.A[j++];
	}
	//copy the remaining elements
	for (int i2 = i; i2 < length; i2++)
		arr3->A[k++] = A[i2];

	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];

	arr3->length = total_length;
	return arr3;
}

template<class T>
Array<T>* Array<T>::Union(Array<T> arr2)
{
	int total_length = (length + arr2.length) * 1.5;
	Array<T>* arr3 = new Array<T>(total_length);
	int i, j, k;
	i = 0, j = 0, k = 0;
	//sort and copy 
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			arr3->A[k++] = arr2.A[j++];
		else
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}
	//copy the remaining elements
	for (; i < length; i++)
		arr3->A[k++] = A[i];

	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];

	arr3->length = k;
	return arr3;
}

template<class T>
Array<T>* Array<T>::Intersection(Array<T> arr2)
{
	int total_length = (length + arr2.length) * 1.5;
	Array<T>* arr3 = new Array<T>(total_length);
	int i, j, k;
	i = 0, j = 0, k = 0;
	//sort and copy 
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			i++;
		else if (arr2.A[j] < A[i])
			j++;
		else if(A[i] == arr2.A[j])
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}
	arr3->length = k;
	return arr3;
}

template<class T >
Array<T>* Array<T>::Difference(Array<T> arr2)
{
	Array<T>* arr3 = new Array<T>((int)(length + arr2.length) * 1.5);
	int i, j, k;
	i = 0, j = 0, k = 0;
	//sort and copy 
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			j++;
		else
		{
			i++; 
			j++;
		}
	}
	//copy the remaining elements in arr1
	for (; i < length; i++)
		arr3->A[k++] = A[i];


	arr3->length = k;
	return arr3;
}

#pragma region Menu Driven Test
void ArrayADT_test()
{
	//Menu driven program
	int ch, sz;
	int x;
	int index;
	

	printf("Enter Size of the array: ");
	std::cin >> sz;
	Array<int>* arr1 = new Array<int>(sz);

	do
	{
		printf("\n\nMenu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Sum\n");
		printf("5. Display\n");
		printf("6. Exit\n");

		printf("enter your choice: ");
		std::cin >> ch;

		switch (ch)
		{
		case 1:
			printf("Enter an element: ");
			std::cin >> x;
			printf("Enter an index to insert: ");
			std::cin >> index;
			arr1->InsertAt(index, x);
			break;
		case 2:
			printf("Enter index: ");
			std::cin >> index;
			x = arr1->DeleteAt(index);
			printf("Deleted Element is %d\n", x);
			break;
		case 3:
			printf("Enter element: ");
			std::cin >> x;
			index = arr1->LinearSearch(x);
			printf("Element index %d", index);
			break;
		case 4:
			printf("Sum is %d\n", arr1->Sum());
			break;
		case 5:
			arr1->Display();
		}


	} while (ch < 6);

}
#pragma endregion