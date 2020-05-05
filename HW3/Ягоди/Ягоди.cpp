#include <iostream>

int findPosition(long long int *boxes, int start, int end, long long int &element)
{
    int mid = start + (end - start) / 2;
    if (mid == 0 && boxes[mid] >= element) //prevents accessing random memory in next else if with boxes[mid-1]
    {
        return 1;
    }
    else if (boxes[mid] >= element && boxes[mid - 1] < element)
    {
        return mid + 1;
    }
    else if (boxes[mid] > element)
    {
        return findPosition(boxes, start, mid - 1, element);
    }
    else if (boxes[mid] < element)
    {
        return findPosition(boxes, mid + 1, end, element);
    }
    return -1;
}

int checkPosition(long long int *boxes, int &length, long long int &element)
{
    return findPosition(boxes, 0, length - 1, element);
}

int main() {

    int n;
    std::cin >> n;

    if (n <= 0)
    {
        return 0;
    }

    long long int *boxes = new long long int[n];

    std::cin >> boxes[0];

    for (int i = 1; i < n; ++i)
    {
        int numberOfStrawberries = 0;
        std::cin >> numberOfStrawberries;
        boxes[i] = numberOfStrawberries + boxes[i - 1]; //store the last index of strawberries into current box
    }

    int m;
    std::cin >> m;

    long long int *strawberries = new long long int[m];

    for (int i = 0; i < m; ++i)
    {
        std::cin >> strawberries[i];
    }

    for (int i = 0; i < m; ++i)
    {
        std::cout << checkPosition(boxes, n, strawberries[i]) << std::endl;
    }

    return 0;
}
