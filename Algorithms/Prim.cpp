#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;

	bool operator<(const Edge & rhs) const
	{
		return weight > rhs.weight;
	}

};

struct Pair
{
	int to;
	int weight;
};

long long int graphWeight(unordered_map<int, list<Pair>> &adj, int start)
{
	unordered_map<int, bool> visited;
	priority_queue<Edge> nextToProcess;
	nextToProcess.push({ start, start, 0 });
	
	Edge current;
	int currentIndex;
	list<Edge> result;
	long long int count = 0;

	while (!nextToProcess.empty())
	{
		current = nextToProcess.top();
		nextToProcess.pop();
		currentIndex = current.to;

		if (!visited[currentIndex])
		{
			result.push_back(current);
			count += current.weight;
			for (auto it = adj[currentIndex].begin(); it != adj[currentIndex].end(); ++it)
			{
				if (!visited[(*it).to])
				{
					nextToProcess.push({ currentIndex,(*it).to,(*it).weight });
				}
			}
		}
		visited[currentIndex] = true;
	}
	return count;
}


int main()
{
	int n, m;
	cin >> n >> m;
	unordered_map<int, list<Pair>> adj;

	int from, to, weight;

	for (int i = 0; i < m; ++i)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to, weight });
		adj[to].push_back({ from, weight });
	}

	cin >> from;

	cout << graphWeight(adj, from);

	return 0;
}
