#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

struct Point
{
    long long int x;
    long long int y;

    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

struct OrderByDistance
{
    bool operator() (Point const &a, Point const &b)
    {
        if ((a.x*a.x + a.y*a.y) < (b.x*b.x + b.y*b.y))
        {
            return true;
        }
        else if ((a.x*a.x + a.y*a.y) == (b.x*b.x + b.y*b.y))
        {
            if (a.x < b.x)
            {
                return true;
            }
            else if (a.x == b.x)
            {
                if (a.y < b.y)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    priority_queue <Point, vector<Point>, OrderByDistance> apartments;
    int N;
    int K;
    scanf("%d", &N);
    scanf("%d", &K);

    int xCoord;
    int yCoord;

    for (int i = 0; i < N; ++i)
    {
        scanf("%d%d", &xCoord, &yCoord);
        Point point{ xCoord,yCoord };
        apartments.push(point);
        if (apartments.size() > K)
        {
            apartments.pop();
        }
    }

    Point *array = new Point[K];
    for (int i = 0; i < K; ++i)
    {
        array[i] = apartments.top();
        apartments.pop();
    }

    for (int i = K - 1; i >= 0; --i)
    {
        printf("%d ", array[i].x);
        printf("%d\n", array[i].y);
    }

    return 0;
}
