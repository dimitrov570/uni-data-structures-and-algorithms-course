#include <iostream>
#include <queue>
using namespace std;

int rowDir[4] = { -1,1,0,0 };
int colDir[4] = { 0,0,1,-1 };


int countNumberOfSteps(char **maze, bool **visited, pair<int, int> start, int N, int M)
{
    queue<int> xCoords;
    queue<int> yCoords;

    xCoords.push(start.first);
    yCoords.push(start.second);
    visited[start.first][start.second] = true;

    int x, y, newX, newY;
    int steps = 0;
    int size = 1;
    int newSize = 0;

    while (!xCoords.empty())
    {
        x = xCoords.front();
        xCoords.pop();

        y = yCoords.front();
        yCoords.pop();

        --size;

        if (maze[x][y] == 'F')
        {
            return steps;
        }

        for (int i = 0; i < 4; ++i)    //add neighbours
        {
            newX = x + rowDir[i];
            newY = y + colDir[i];

            if (newX < 0 || newY < 0 || newX >= N || newY >= M)
            {
                continue;
            }
            if (visited[newX][newY])
            {
                continue;
            }
            if (maze[newX][newY] == '#')
            {
                continue;
            }
            xCoords.push(newX);
            yCoords.push(newY);
            visited[newX][newY] = true;
            ++newSize;
        }

        //add portals
        newX = x;
        while (newX + 1 < N && maze[newX + 1][y] != '#')
        {
            ++newX;
        }
        if (newX != x && !visited[newX][y])
        {
            xCoords.push(newX);
            yCoords.push(y);
            ++newSize;
        }

        newX = x;
        while (newX - 1 > 0 && maze[newX - 1][y] != '#')
        {
            --newX;
        }
        if (newX != x && !visited[newX][y])
        {
            xCoords.push(newX);
            yCoords.push(y);
            ++newSize;
        }

        newY = y;
        while (newY + 1 < M && maze[x][newY + 1] != '#')
        {
            ++newY;
        }
        if (newY != y && !visited[x][newY])
        {
            xCoords.push(x);
            yCoords.push(newY);
            ++newSize;
        }

        newY = y;
        while (newY - 1 < M && maze[x][newY - 1] != '#')
        {
            --newY;
        }
        if (newY != y && !visited[x][newY])
        {
            xCoords.push(x);
            yCoords.push(newY);
            ++newSize;
        }

        if (size <= 0)
        {
            size = newSize;
            newSize = 0;
            ++steps;
        }

    }
    return -1;
}

int main()
{
    int N, M;

    cin >> N >> M;

    char **maze = new char*[N];
    bool **visited = new bool*[N];
    for (int i = 0; i < N; ++i)
    {
        maze[i] = new char[M];
        visited[i] = new bool[M];
    }

    pair<int, int> startCoordinates;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> maze[i][j];
            visited[i][j] = false;
            if (maze[i][j] == 'S')
            {
                startCoordinates = { i,j };
            }
        }
    }

    cout << countNumberOfSteps(maze, visited, startCoordinates, N, M);

    return 0;
}
