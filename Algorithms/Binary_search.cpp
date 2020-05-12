#include <iostream>

int binarySearching(int *arr, int start, int end, int element)
{
		int mid = (start + end) / 2;
		if (arr[mid] == element)
		{
			return mid + 1;
		}
		else if (arr[mid] > element)
		{
			return binarySearching(arr, start, mid - 1, element);
		}
		else
		{
			return binarySearching(arr, mid + 1, end, element);
		}
	return -1;
}

int binarySearch(int *arr, int length, int element)
{
	return binarySearching(arr, 0, length - 1, element);
}

int main()
{

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	std::cout << binarySearch(arr, 10, 2);

	return 0;
}
