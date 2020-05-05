#include <iostream>
#include <stack>

int findMaximumVisibleTrees(int *trees, int length)
{
    std::stack<int> visibleTrees;
    int index = -1;
    int maxSize = 0;
    visibleTrees.push(trees[length - 1]);
    for (int i = length - 2; i >= -1; --i)
    {
        while (i >= 0 && trees[i] < visibleTrees.top())
        {
            visibleTrees.push(trees[i]);
            --i;
        }
        if (maxSize <= visibleTrees.size())
        {
            maxSize = visibleTrees.size();
            index = i + 1;
        }
        while (i >= 0 && !visibleTrees.empty() && trees[i] >= visibleTrees.top())
        {
            visibleTrees.pop();
        }
        if (i >= 0)
        {
            visibleTrees.push(trees[i]);
        }
    }
    return index;
}

int main() {
    int N;
    std::cin >> N;
    int *trees = new int[N];
    for (int i = 0; i < N; ++i)
    {
        std::cin >> trees[i];
    }
    std::cout << findMaximumVisibleTrees(trees, N);
    return 0;
}
