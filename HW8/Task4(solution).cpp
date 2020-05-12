#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;


struct Edge
{
    int index;
    int distance;

    bool operator<(const Edge & rhs) const {
        return distance > rhs.distance;
    }

};

void search(unordered_map<int, list<Edge>> &adj, int start, vector<int> &result)
{
    unordered_map<int, bool> visited;
    priority_queue<Edge> vertices;
    vertices.push({ start, 0 });
    result[start] = 0;

    Edge currentEdge;
    int currentIndex;

    while (!vertices.empty())
    {
        currentEdge = vertices.top();
        vertices.pop();

        currentIndex = currentEdge.index;

        if (visited[currentIndex])
        {
            continue;
        }

        visited[currentIndex] = true;

        for (auto it = adj[currentIndex].begin(); it != adj[currentIndex].end(); ++it)
        {
            if (result[currentIndex] + (*it).distance < result[(*it).index])
            {
                result[(*it).index] = result[currentIndex] + (*it).distance;
                vertices.push({ (*it).index ,result[(*it).index] });
            }
        }

    }
}

int main()
{
    int N, M, K, Q;
    cin >> N >> M;

    int from, to, distance;

    unordered_map<int, list<Edge>> adj;

    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> distance;
        adj[from].push_back({ to, distance });
        adj[to].push_back({ from, distance });
    }

    cin >> K;
    int *discos = new int[K];

    for (int i = 0; i < K; ++i)
    {
        cin >> discos[i];
        adj[N + 1].push_back({ discos[i],0 });
    }

    cin >> Q;
    int *dorms = new int[Q];

    for (int i = 0; i < Q; ++i)
    {
        cin >> dorms[i];
    }

    vector<int> result(N + 2, INT_MAX);

    search(adj, N + 1, result);

    for (int i = 0; i < Q; ++i)
    {
        cout << result[dorms[i]] << '\n';
    }

    return 0;
}
