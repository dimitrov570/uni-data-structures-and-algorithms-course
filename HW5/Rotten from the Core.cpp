#include <iostream>
#include <queue>

int N, M, T;
int numberOfApples = 0;
int newNumberOfApples = 0;
int numberOfInfectedApples = 0;

bool isValidPosition(std::pair<int, int> *position, bool **rottenApples)
{
    if (position->first > N || position->second > M)
    {
        return false;
    }
    else if (position->first <= 0 || position->second <= 0)
    {
        return false;
    }
    else if (rottenApples[position->first - 1][position->second - 1] == 1)
    {
        return false;
    }
    return true;
}

void infectApples(std::queue<std::pair<int, int>> *apples, std::pair<int, int> currentPosition, bool **rottenApples)
{
    std::pair<int, int> position;
    position.first = currentPosition.first + 1;
    position.second = currentPosition.second;
    if (isValidPosition(&position, rottenApples))
    {
        rottenApples[position.first - 1][position.second - 1] = 1;
        ++newNumberOfApples;
        apples->push(position);
    }

    position.first -= 2;
    if (isValidPosition(&position, rottenApples))
    {
        rottenApples[position.first - 1][position.second - 1] = 1;
        ++newNumberOfApples;
        apples->push(position);
    }

    ++position.first;
    ++position.second;
    if (isValidPosition(&position, rottenApples))
    {
        rottenApples[position.first - 1][position.second - 1] = 1;
        ++newNumberOfApples;
        apples->push(position);
    }

    position.second -= 2;
    if (isValidPosition(&position, rottenApples))
    {
        rottenApples[position.first - 1][position.second - 1] = 1;
        ++newNumberOfApples;
        apples->push(position);
    }
}

int main()
{
    std::queue<std::pair<int, int>> apples;

    std::cin >> N >> M >> T;

    bool **rottenApples = new bool*[N];

    for (int i = 0; i < N; ++i)
    {
        rottenApples[i] = new bool[M];
    }

    std::pair<int, int> *positions = new std::pair<int, int>[N*M];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            rottenApples[i][j] = 0;
        }
    }

    int row, column;
    std::pair<int, int> position;
    while (std::cin >> row >> column)
    {
        position.first = row;
        position.second = column;
        apples.push(position);
        rottenApples[row - 1][column - 1] = 1;
        ++numberOfApples;
        ++numberOfInfectedApples;
    }

    while (!apples.empty() && T > 0)
    {
        while (numberOfApples > 0)
        {
            infectApples(&apples, apples.front(), rottenApples);
            apples.pop();
            --numberOfApples;
        }
        numberOfApples = newNumberOfApples;
        newNumberOfApples = 0;
        numberOfInfectedApples += numberOfApples;
        --T;
    }

    std::cout << N*M - numberOfInfectedApples;

    return 0;
}
