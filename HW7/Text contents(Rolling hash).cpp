#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//FIRST HASH
const int BASE_ONE  = 257;
const long long int MOD_ONE = 988959600479;
long long int magicOne = 1;
long long int rollingHashOne = 0;

void appendOne(char ch)
{
    rollingHashOne = (rollingHashOne*BASE_ONE + ch) % MOD_ONE;
    magicOne = magicOne * BASE_ONE % MOD_ONE;
}

void shiftOne(char first, char last)
{
    rollingHashOne = (rollingHashOne * BASE_ONE - first * magicOne + last) % MOD_ONE;
}

//SECOND HASH
const int BASE_TWO = 823;
const long long int MOD_TWO = 955959567881;
long long int magicTwo = 1;
long long int rollingHashTwo = 0;

void appendTwo(char ch)
{
    rollingHashTwo = (rollingHashTwo*BASE_TWO + ch) % MOD_TWO;
    magicTwo = magicTwo * BASE_TWO % MOD_TWO;
}

void shiftTwo(char first, char last)
{
    rollingHashTwo = (rollingHashTwo * BASE_TWO - first * magicTwo + last) % MOD_TWO;
}

int main()
{
    int N, K;
    int maxOccurences = 0;    
    int startingIndex = 0;
    unordered_map<long long int, int> occ;
    string text;
    
    cin >> N >> K;
    cin.ignore();
    getline(cin, text);

    for (int i = 0; i < K; ++i)
    {
        appendOne(text[i]);
        appendTwo(text[i]);
    }
    
    ++occ[rollingHashOne+rollingHashTwo];
    maxOccurences = 1;

    for (int i = 0; i < N - K; ++i)
    {
        shiftOne(text[i], text[i + K]);
        shiftTwo(text[i], text[i + K]);
        if (++occ[rollingHashOne+rollingHashTwo] >= maxOccurences)
        {
            startingIndex = i + 1;
            maxOccurences = occ[rollingHashOne + rollingHashTwo];
        }
    }

    cout << text.substr(startingIndex, K);

    return 0;
}
