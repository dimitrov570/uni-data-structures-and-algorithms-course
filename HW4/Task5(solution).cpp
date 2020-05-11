#include <iostream>
#include <stack>

bool checkTrucks(int *positions, int length)
{
    std::stack <int> street;
    int currentPosition = 1;
    for (int i = 0; i <= length; ++i)
    {
        while (!street.empty() && street.top() == currentPosition)
        {
            street.pop();
            ++currentPosition;
            continue;
        }
        while (i < length && currentPosition != positions[i])
        {
            street.push(positions[i]);
            ++i;
        }
        ++currentPosition;
    }
    if (street.empty())
    {
        return true;
    }
    return false;
}

int main() {
    int T;
    std::cin >> T;
    int *numberOfTrucks = new int[T];
    int **positions = new int*[T];
    for (int i = 0; i < T; ++i)
    {
        std::cin >> numberOfTrucks[i];
        positions[i] = new int[numberOfTrucks[i]];

        for (int j = 0; j < numberOfTrucks[i]; ++j)
        {
            std::cin >> positions[i][j];
        }
    }

    for (int i = 0; i < T; ++i)
    {
        if (checkTrucks(positions[i], numberOfTrucks[i]))
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }
    return 0;
}
