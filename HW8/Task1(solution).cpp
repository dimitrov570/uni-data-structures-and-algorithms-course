#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
using namespace std;

void findPathRecursive(unordered_map<string, list<string>> &map, vector<string> &result, string &current, unordered_map<string, bool> &visited, bool &found)
{
    result.push_back(current);
    visited[current] = true;


    for (auto it = map[current].begin(); it != map[current].end(); ++it)
    {
        
        if (*it == *(result.begin()))
        {
            found = true;
            result.push_back(*it);
            return;
        }
        if (!visited[*it])
        {
            findPathRecursive(map, result, *it, visited, found);
        }
        if (found == true)
        {
            return;
        }
    }
    result.pop_back();
}

void findPath(unordered_map<string, list<string>> &map, vector<string> &result, string &start)
{
    unordered_map<string, bool> visited;
    bool found = false;
    findPathRecursive(map, result, start, visited, found);
}

int main()
{
    int N, M;
    cin >> N >> M;

    unordered_map<string, list<string>> map;

    string from, to;

    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        map[from].push_back(to);
    }

    vector<string> result;

    cin >> from;

    findPath(map, result, from);
    
    if (result.size() <= 1)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
    }

}
