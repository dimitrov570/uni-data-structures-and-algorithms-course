#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;

    cin >> n >> m;

    int *sets = new int[n + 1];

    int from, to;

    for (int i = 0; i <= n; ++i)
    {
        sets[i] = i;
    }
    int oldSet;
    int newSet;
    for (int i = 0; i < m; ++i)
    {
        cin >> from >> to;
        oldSet = sets[from];
        newSet = sets[to];
        for (int j = 0; j <= n; ++j)
        {
            if (sets[j] == oldSet)
            {
                sets[j] = newSet;
            }
        }
    }

    int q;
    cin >> q;
    int command;
    for (int i = 0; i < q; ++i)
    {
        cin >> command >> from >> to;
        if (command == 1)
        {
            cout << (sets[from] == sets[to]);
        }
        else if (command == 2)
        {
            oldSet = sets[from];
            newSet = sets[to];
            if (oldSet != newSet)
            {
                for (int j = 0; j <= n; ++j)
                {
                    if (sets[j] == oldSet)
                    {
                        sets[j] = newSet;
                    }
                }
            }
        }
    }

    return 0;
}
