#include <iostream>

int main()
{
    int N, K;
    std::cin >> N >> K;
    int *array = new int[N];

    for (int i = 0; i < N; ++i)
    {
        std::cin >> array[i];
    }

    int i = 0;
    int j = 0;
    int min;
    int max;
    int maxIndex;
    int minIndex;
    long long int numberOfElements;
    long long int start;
    long long int end;
    long long int answer = 0;
    while (i < N)
    {
        min = max = array[i];
        maxIndex = minIndex = i;
        numberOfElements = 1;
        j = i + 1;
        while (j < N) //finding longest subarray from position 'i' that matches the criteria
        {
            if (array[j] > max)
            {
                max = array[j];
                maxIndex = j;
            }
            else if (array[j] < min)
            {
                min = array[j];
                minIndex = j;
            }
            if ((max - min) > K)
            {
                break;
            }
            ++numberOfElements;
            ++j;
        }
        end = j;
        answer += (numberOfElements * (numberOfElements - 1)) / 2; //number of combinations of n elements
        i = maxIndex > minIndex ? minIndex : maxIndex; //starting one position away from first point that broke the condition
        ++i;
        start = i;
        answer -= (end - start)*(end - start - 1) / 2; //eliminating number of combinations from the point that broke the condition till position 'j', because in next iterations we are going to count them
    }

    std::cout << answer + N; //+N because the elements alone match the condition (array[i]-array[i] = 0 <= K) since K>=0

    return 0;
}
