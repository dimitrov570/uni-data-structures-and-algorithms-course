#include <iostream>


int oneShotCounter(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n <= 40 && n % 2 == 0)
    {
        return 1;
    }
    else if (n == 50)
    {
        return 1;
    }
    return 0;
}

int twoShotsCounter(int n)
{
    int counter = 0;

    for (int i = 0; i <= 20; ++i)
    {
        if (oneShotCounter(n - i) > 0)
        {
            ++counter;
        }
        if (oneShotCounter(n - 2 * i) > 0 && i != 0)
        {
            ++counter;
        }
        if (oneShotCounter(n - 3 * i) > 0 && i != 0)
        {
            ++counter;
        }
    }

    if (oneShotCounter(n - 25) > 0)
    {
        ++counter;
    }
    if (oneShotCounter(n - 50) > 0)
    {
        ++counter;
    }
    
    return counter;
}

int threeShotsCounter(int n)
{
    int counter = 0;
    
    for (int i = 0; i <= 20; ++i)
    {
        for (int j = 0; j <= 20; ++j)
        {
            if (oneShotCounter(n - i - j) > 0)
            {
                ++counter;
            }
            if (oneShotCounter(n - 2 * i - j) > 0 && i != 0)
            {
                ++counter;
            }
            if (oneShotCounter(n - 3 * i - j) > 0 && i != 0)
            {
                ++counter;
            }
            if (oneShotCounter(n - i - 2 * j) > 0 && j != 0)
            {
                ++counter;
            }
            if (oneShotCounter(n - i - 3 * j) > 0 && j != 0)
            {
                ++counter;
            }
            if (oneShotCounter(n - 2 * i - 3 * j) > 0 && i != 0 && j != 0)
            {
                ++counter;
            }
            if (oneShotCounter(n - 3 * i - 2 * j) > 0 && i != 0 && j != 0)
            {
                ++counter;
            }
            if (oneShotCounter(n - 3 * i - 3 * j) > 0 && i != 0 && j != 0)
            {
                ++counter;
            }
            if (oneShotCounter(n - 2 * i - 2 * j) > 0 && i != 0 && j != 0)
            {
                ++counter;
            }
        }
        //25
        if (oneShotCounter(n - i - 25) > 0)
        {
            counter += 2;
        }
        if (oneShotCounter(n - 2 * i - 25) > 0 && i != 0)
        {
            counter+=2;
        }
        if (oneShotCounter(n - 3 * i - 25) > 0 && i != 0)
        {
            counter += 2;
        }
        //50
        if (oneShotCounter(n - i - 50) > 0)
        {
            counter += 2;
        }
        if (oneShotCounter(n - 2 * i - 50) > 0 && i != 0)
        {
            counter += 2;
        }
        if (oneShotCounter(n - 3 * i - 50) > 0 && i != 0)
        {
            counter += 2;
        }
    }
    //2x25
    if (oneShotCounter(n - 50) > 0)
    {
        ++counter;
    }
    //75
    if (oneShotCounter(n - 75) > 0)
    {
        counter += 2;
    }
    if (oneShotCounter(n - 100) > 0)
    {
        ++counter;
    }
    return counter;
}

int counter(int n)
{
    return oneShotCounter(n) + twoShotsCounter(n) + threeShotsCounter(n);
}

int main() {
    
    int N;

    std::cin >> N;

    std::cout << counter(N);
    
    return 0;
}
