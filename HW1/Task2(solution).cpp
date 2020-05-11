#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int M, N;

    std::cin >> M;
    std::cin >> N;

    long int grades = 0;
    long int grade;
    
    int i = N;
    while (i > 0)
    {
        std::cin >> grade;
        grades += grade;
        --i;
    }
    
    if (N == 0)
    {
        std::cout << "yes";
    }
    else if ((grades / N) >= M)
    {
        std::cout << "yes";
    }
    else
    {
        std::cout << "no";
    }

    return 0;
}
