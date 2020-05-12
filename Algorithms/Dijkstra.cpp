#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Pair
{
	int to;
	long long int length;

	bool operator<(const Pair & rhs) const
	{
		return length > rhs.length;
	}
};

void calcDistances(unordered_map<int, list<Pair>> &adj, vector<long long int> &distances, int start, int n)
{
	for (int i = 0; i < n + 1; ++i)
	{
		distances[i] = LLONG_MAX;
	}
	unordered_map<int, bool> visited;
	priority_queue<Pair> next;
	next.push({ start, 0 });
	distances[start] = 0;
	int currentIndex;
	Pair currentPair;

	while (!next.empty())
	{
		currentPair = next.top();
		currentIndex = currentPair.to;
		next.pop();

		if (visited[currentIndex])
		{
			continue;
		}

		visited[currentIndex] = true;

		for (auto it = adj[currentIndex].begin(); it != adj[currentIndex].end(); ++it)
		{
			if (distances[currentIndex] + (*it).length < distances[(*it).to])
			{
				distances[(*it).to] = distances[currentIndex] + (*it).length;
				next.push({ (*it).to, distances[(*it).to] });
			}
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	int from, to, length;
	unordered_map<int, list<Pair>> adj;

	for (long long int i = 0; i < m; ++i)
	{
		cin >> from >> to >> length;
		adj[from].push_back({ to, length });
		adj[to].push_back({ from, length });
	}

	cin >> from;

	vector<vector<long long int>> distances(n + 1);
	for (int i = 0; i < n; ++i)
	{
		distances[i].reserve(n + 1);
	}

	unordered_map<int, bool> visited;

	calcDistances(adj, distances[from], from, n);

return 0;
}
