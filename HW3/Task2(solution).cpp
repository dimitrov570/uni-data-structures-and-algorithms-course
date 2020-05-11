#include <iostream>

void merge(long long int *arr, long long int *tmpArr, int start, int mid, int end)
{
    int leftPointer = start;
    int rightPointer = mid + 1;

    for (int i = start; i <= end; ++i)
    {
        if (leftPointer <= mid && (rightPointer > end || arr[leftPointer] <= arr[rightPointer]))
        {
            tmpArr[i] = arr[leftPointer++];
        }
        else
        {
            tmpArr[i] = arr[rightPointer++];
        }
    }

    for (int i = start; i <= end; ++i)
    {
        arr[i] = tmpArr[i];
    }
}

void mergeSorting(long long int *arr, long long int *tmpArr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSorting(arr, tmpArr, start, mid);
        mergeSorting(arr, tmpArr, mid + 1, end);
        merge(arr, tmpArr, start, mid, end);
    }
}

void mergeSort(long long int *arr, int length)
{
    long long int* tmpArr = new long long int[length];
    mergeSorting(arr, tmpArr, 0, length - 1);
    delete[] tmpArr;
}

bool checkIfPossible(long long int *arr, int length, long long int mid, int numberOfCows)
{
    int cowPosition = arr[0]; //place first cow at first hut from the left
    --numberOfCows;

    for (int i = 1; i < length; ++i)
    {
        if (arr[i] - cowPosition >= mid)
        {
            cowPosition = arr[i];
            --numberOfCows;
        }
        if (numberOfCows == 0) //if all cows are placed
        {
            return true;
        }
    }

    return false;
}

long long int findDistance(long long int *arr, int length, int numberOfCows)
{
    if (numberOfCows == 2)
    {
        return arr[length - 1] - arr[0];
    }

    long long int minimumDistance = 0;

    long long int leftPointer = 0;
    long long int rightPointer = arr[length - 1] - arr[0] + 1; // this is maximum possible distance between two cows
    long long int mid = 0;

    while (leftPointer < rightPointer)
    {
        mid = leftPointer + (rightPointer - leftPointer) / 2;

        if (checkIfPossible(arr, length, mid, numberOfCows))
        {
            minimumDistance = mid; //if mid distance is possible to achieve, try with bigger distance
            leftPointer = mid + 1;
        }
        else //try with smaller distance
        {
            rightPointer = mid;
        }
    }
    return minimumDistance;
}

int main() {

    int N, K;
    std::cin >> N >> K;

    long long int *huts = new long long int[N];

    for (int i = 0; i < N; ++i)
    {
        std::cin >> huts[i];
    }

    mergeSort(huts, N);

    std::cout << findDistance(huts, N, K);

    delete[] huts;

    return 0;
}
