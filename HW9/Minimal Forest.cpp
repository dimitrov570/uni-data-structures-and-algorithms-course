#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

struct Edge
{
    int from;
    int to;
    long long int weight;

    bool operator<(const Edge & rhs) const
    {
        return weight > rhs.weight;
    }

};

struct Pair
{
    int to;
    long long int weight;
};

long long int graphWeight(unordered_map<int, list<Pair>> &adj, priority_queue<Edge> &edges, int numberOfEdges)
{
    list<Edge> tree;
    Edge current;
    long long int count = 0;

    unordered_map<int, bool> visited;
    int oldSet;
    int *components = new int[numberOfEdges];
    for (int i = 0; i < numberOfEdges; ++i)
    {
        components[i] = i;
    }

    while (!edges.empty())
    {
        current = edges.top();
        edges.pop();

        if (components[current.from] != components[current.to])
        {
            tree.push_back(current);
            count += current.weight;
            oldSet = components[current.from];
            for (int i = 0; i < numberOfEdges; ++i)
            {
                if (components[i] == oldSet)
                {
                    components[i] = components[current.to];
                }
            }
        }
    }
    return count;
}


int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, list<Pair>> adj;
    priority_queue<Edge> edges;
    int from, to;
    long long int weight;

    for (int i = 0; i < m; ++i)
    {
        cin >> from >> to >> weight;
        adj[from].push_back({ to, weight });
        adj[to].push_back({ from, weight });

        edges.push({ from, to, weight });
        edges.push({ to, from, weight });
    }

    cout << graphWeight(adj, edges, n);

    return 0;
}
