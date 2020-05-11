#include <iostream>

//checking number of monsters needed to place all trucks at a given position
long long int check(int *trucks, int *monstersPerTruck, int length, int position)
{
    long long int numberOfMonsters = 0;
    for (int i = 0; i < length; ++i)
    {
        numberOfMonsters += abs(position - trucks[i]) * monstersPerTruck[i];
    }
    return numberOfMonsters;
}

//using ternary search to discover at which position Kyle would take the least effort to move trucks
long long int findMinimumAmountOfMonsters(int *trucks, int *monstersPerTruck, int length, int maxBehind, int maxInFront)
{
    int left = maxBehind;
    int right = maxInFront;
    int firstThird;
    int secondThird;

    long long int answer = 0;

    while (left <= right)
    {
        int difference;
        
        if (abs(difference = right - left) < 3) //if difference is less than 3 "firstThird" and "secondThird"
        {                                       //will be the same in some cases where they shouldn't be the same
            difference = 3;
        }
        
        firstThird = left + difference / 3;
        secondThird = right - difference / 3;

        if (check(trucks, monstersPerTruck, length, firstThird) < check(trucks, monstersPerTruck, length, secondThird))
        {
            answer = check(trucks, monstersPerTruck, length, firstThird);
            right = secondThird;
        }
        else
        {
            answer = check(trucks, monstersPerTruck, length, secondThird);
            left = firstThird;
        }
    }
    return answer;
}

int main() {

    int N;
    std::cin >> N;

    int maxBehind = 10000;
    int maxInFront = -10000;

    int *trucks = new int[N];
    int *monstersPerTruck = new int[N];

    for (int i = 0; i < N; ++i)
    {
        std::cin >> trucks[i] >> monstersPerTruck[i];
        if (trucks[i] < maxBehind)
        {
            maxBehind = trucks[i]; //trucks will be placed somewhere between the farthest trucks at both ends
        }
        if (trucks[i] > maxInFront)
        {
            maxInFront = trucks[i];
        }
    }

    std::cout << findMinimumAmountOfMonsters(trucks, monstersPerTruck, N, maxBehind - 1, maxInFront + 1);

    delete[] trucks;
    delete[] monstersPerTruck;
    
    return 0;
}
