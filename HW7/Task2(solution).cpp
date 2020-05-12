#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    queue<pair<int,int>> roomKeys; // .first stores key in the room and .second stores key needed to open the door
    unordered_map<int,int> keyMap;
    int *keyInRoom = new int[N - 1];
    int key;

    for (int i = 0; i < N - 1; ++i)
    {
        scanf("%d", &key);
        keyInRoom[i] = key;
    }

    for (int i = 0; i < N - 1; ++i)
    {
        scanf("%d", &key);
        roomKeys.push(pair<int,int>(keyInRoom[i],key));
    }

    int result = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        ++keyMap[roomKeys.front().first];
        if (!keyMap[roomKeys.front().second])
        {
            ++result;
        }
        else
        {
            --keyMap[roomKeys.front().second];
        }
        roomKeys.pop();
    }

    cout << result;

    return 0;
}
