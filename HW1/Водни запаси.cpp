#include <iostream>

int main() {
    
    int n;
    std::cin >> n;
    int *walls = new int[n];

    int i = n;
    while ((--i) >= 0)
    {
        std::cin >> walls[i];
    }

    int S = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int smaller = (walls[i] < walls[j]) ? walls[i] : walls[j];
            S = (S > (smaller*(j - i))) ? S : (smaller*(j - i));
        }
    }

    std::cout << S;

    delete[] walls;
    return 0;
}
