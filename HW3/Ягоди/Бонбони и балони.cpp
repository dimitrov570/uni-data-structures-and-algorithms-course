#include <iostream>
#include <climits>

long long int max(long long int number1, long long int number2)
{
    return number1 < number2 ? number2 : number1;
}

bool check(long long int *balloons, long long int *candies, int length, 
    unsigned long long int numberOfBalloons, unsigned long long int possibleNumberOfCandies)
{
    unsigned long long int balloonsNeeded = 0;
    
    //counting how many balloons would be needed if maximum "possibleNumberOfCandies" per day can be given
    for (int i = 0; i < length; ++i)
    {
        balloonsNeeded += max(0, balloons[i] - possibleNumberOfCandies / candies[i]);
    }
        if (numberOfBalloons < balloonsNeeded)
        {
            return false;
        }
    return true;
}

long long int checkForMaximumNumberOfCandies(long long int *balloons, long long int *candies,
    int length, unsigned long long int numberOfBalloons,  unsigned long long int maxNrOfCandies)
{
    unsigned long long int start = 0;
    unsigned long long int mid = 0;
    unsigned long long int end = maxNrOfCandies;
    unsigned long long int answer = 0;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (check(balloons, candies, length, numberOfBalloons, mid))
        {
            answer = mid;
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return answer;
}

int main() {

    int N;
    unsigned long long int M;
    std::cin >> N;
    std::cin >> M;

    long long int *balloons = new long long int[N];
    long long int *candies = new long long int[N];

    for (long int i = 0; i < N; ++i)
    {
        std::cin >> balloons[i];
    }

    for (long int i = 0; i < N; ++i)
    {
        std::cin >> candies[i];
    }

    unsigned long long int maxNumberOfCandies = ULLONG_MAX;

    std::cout << checkForMaximumNumberOfCandies(balloons, candies, N, M, maxNumberOfCandies);

    delete[] balloons;
    delete[] candies;
    
    return 0;
}
