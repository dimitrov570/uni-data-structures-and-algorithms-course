#include <iostream>


void merge(int *arr, int *tmpArr, int start, int mid, int end)
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

int blastCounter(int *arr, int n, int x)
{
    if (n == 0)
    {
        return 0;
    }

    int blasts = 0;

    int blastIndex = n - 1;

    while (arr[blastIndex] - blasts * x > 0)
    {
        while (blastIndex > 0 && arr[blastIndex - 1] == arr[blastIndex])
        {
            blastIndex--;
        }

        blastIndex--;
        blasts++;

        if (blastIndex < 0)
        {
            break;
        }
    }
    return blasts;
}

int main() {

    int n, x;
    std::cin >> n >> x;

    int *monsters = new int[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> monsters[i];
    }

    mergeSort(monsters, n);

    std::cout << blastCounter(monsters, n, x);

    delete[] monsters;

    return 0;
}
