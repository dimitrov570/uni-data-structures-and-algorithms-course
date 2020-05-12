#include <iostream>

using namespace std;

void floydWarshall(long long int **adj, int n)
{
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
				{
					continue;
				}
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	long long int **adj = new long long int*[n];
	for (int i = 0; i < n; ++i)
	{
		adj[i] = new long long int[n];
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				adj[i][j] = 0;
			}
			else
			{
				adj[i][j] = INT_MAX;
			}
		}
	}

	int from, to, weight;

	for (int i = 0; i < m; ++i)
	{
		cin >> from >> to >> weight;
		adj[from - 1][to - 1] = weight;
	}

	floydWarshall(adj, n);

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> from >> to;
		if (adj[from - 1][to - 1] >= INT_MAX)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << adj[from - 1][to - 1] << '\n';
		}
	}

	return 0;
}
