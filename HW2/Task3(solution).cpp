#include <iostream>

long int price = 0;

void merge(int *arr, int *tmpArr, int start, int mid, int end)
{
    int leftPointer = start;
    int rightPointer = mid + 1;
    int sortedIndex = start;

    while (leftPointer <= mid && rightPointer <= end) 
        {
            if (arr[leftPointer] <= arr[rightPointer]) 
            {
                tmpArr[sortedIndex] = arr[leftPointer];
                leftPointer++;
            }
            else 
            {
                tmpArr[sortedIndex] = arr[rightPointer];
                rightPointer++;
                price += mid - leftPointer + 1; //counting the how many numbers are 
                                                //bigger than the current smallest of second part of the array 
            }

            sortedIndex++;
        }

    while (leftPointer <= mid) 
        {
            tmpArr[sortedIndex] = arr[leftPointer];
            leftPointer++;
            sortedIndex++;
        }
    
    while (rightPointer <= end) 
        {
            tmpArr[sortedIndex] = arr[rightPointer];
            rightPointer++;
            sortedIndex++;
        }

    for (int i = start; i <= end; i++) 
        {
            arr[i] = tmpArr[i];
        }
}

void mergeSorting(int *arr, int *tmpArr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSorting(arr, tmpArr, start, mid);
        mergeSorting(arr, tmpArr, mid + 1, end);
        merge(arr, tmpArr, start, mid, end);
    }
}

void mergeSort(int *arr, int length)
{
    int* tmpArr = new int[length];
    mergeSorting(arr, tmpArr, 0, length - 1);
    delete[] tmpArr;
}

int main() {

    int N;
    std::cin >> N;

    int *heights = new int[N];

    for (int i = 0; i < N; ++i)
    {
        std::cin >> heights[i];
    }

    mergeSort(heights, N);

    std::cout << price;

    return 0;
}
