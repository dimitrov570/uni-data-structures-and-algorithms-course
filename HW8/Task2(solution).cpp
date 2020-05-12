#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

void DFS(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for (auto it = adj[node].begin(); it != adj[node].end(); ++it)
    {
        if (!visited[*it])
        {
            DFS(*it, adj, visited);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    unordered_map<int, list<int>> adj;

    int from, to;

    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int result = 0;

    unordered_map<int, bool> visited;

    for (auto it = adj.begin(); it != adj.end(); ++it)
    {
        if (!visited[(*it).first])
        {
            DFS((*it).first, adj, visited);
            ++result;
        }
    }

    cout << result + N - adj.size();

    return 0;
}
