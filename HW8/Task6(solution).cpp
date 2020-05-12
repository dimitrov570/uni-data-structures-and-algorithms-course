#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

long long int countNumberOfPaths(unordered_map<int, list<int>> &adj, vector<int> &edges, int from, int to)
{
    vector<int> topSorted;
    queue<int> zeroQueue;

    for (int i = 0; i < edges.size(); ++i)
    {
        if (!edges[i])
        {
            zeroQueue.push(i);
        }
    }

    int curr;
    int startIndex;
    int endIndex;

    while (!zeroQueue.empty())
    {
        curr = zeroQueue.front();
        zeroQueue.pop();
        topSorted.push_back(curr);
        if (curr == from)
        {
            startIndex = topSorted.size() - 1;
        }
        else if (curr == to)
        {
            endIndex = topSorted.size() - 1;
        }

        for (auto it = adj[curr].begin(); it != adj[curr].end(); ++it)
        {
            --edges[*it];
            if (!edges[*it])
            {
                zeroQueue.push(*it);
            }
        }
    }

    unordered_map<int, long long int> numberOfWays;

    numberOfWays[to] = 1;

    for (int i = endIndex - 1; i >= startIndex; --i)
    {
        for (auto it = adj[topSorted[i]].begin(); it != adj[topSorted[i]].end(); ++it)
        {
            numberOfWays[topSorted[i]] += numberOfWays[*it];
            numberOfWays[topSorted[i]] %= 1000000007;
        }
    }

    return numberOfWays[from];
}

int main()
{
    int N, M;

    cin >> N >> M;

    vector<int> edges(N + 1, 0);

    int from, to;
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        ++edges[to];
    }

    cin >> from >> to;

    cout << countNumberOfPaths(adj, edges, from, to) % 1000000007;

    return 0;
}
