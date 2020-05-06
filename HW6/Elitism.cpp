#include <iostream>
#include <queue>
#include <iomanip>
#include<stdio.h> 

std::priority_queue<int> bottomElements;
std::priority_queue < long long int, std::deque<long long int>, std::greater<long long int> > topElements;

void balanceQueues()
{
    if (bottomElements.size() == topElements.size())
    {
        return;
    }
    if (bottomElements.size() < topElements.size())
    {
        bottomElements.push(topElements.top());
        topElements.pop();
    }
    else
    {
        topElements.push(bottomElements.top());
        bottomElements.pop();
    }
}

int main() {

    int N;
    std::cin >> N;

    int data;
    scanf("%d", &data);
    bottomElements.push(data);
    double median;
    median = (double)data;
    printf("%.1f \n", median);

    for (long long int i = 1; i < N; ++i)
    {
        scanf("%d", &data);
        if (data < bottomElements.top())
        {
            bottomElements.push(data);
            balanceQueues();
        }
        else
        {
            topElements.push(data);
            balanceQueues();
        }
        if (bottomElements.size() == topElements.size())
        {
            median = (double)(bottomElements.top() + topElements.top()) / 2.0;
        }
        else if (bottomElements.size() > topElements.size())
        {
            median = (double)(bottomElements.top());
        }
        else
        {
            median = (double)(topElements.top());
        }

        printf("%.1f \n", median);
    }

    return 0;
}
