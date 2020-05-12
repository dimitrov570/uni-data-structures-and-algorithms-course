#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct Node
{
    Node *next[ALPHABET_SIZE];
    int numberOfWords;
    bool isEnd;

    Node()
    {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            next[i] = nullptr;
        }
        numberOfWords = 0;
        isEnd = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node;
    }

    void insert(const string word)
    {
        Node *tmp = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (!tmp->next[word[i] - 'a'])
            {
                tmp->next[word[i] - 'a'] = new Node;
            }
            tmp = tmp->next[word[i] - 'a'];
            ++(tmp->numberOfWords);
        }
        tmp->isEnd = true;
    }

    int numberOfWords(const string prefix)    //returns number of words, for which given string is a prefix
    {                                         //works only if a single word is inserted not more than once
        Node *tmp = root;

        for (int i = 0; i < prefix.size(); ++i)
        {
            if (!tmp->next[prefix[i] - 'a'])
            {
                return 0;
            }
            tmp = tmp->next[prefix[i] - 'a'];
        }
        return tmp->numberOfWords;
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    Trie trie;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        trie.insert(str);
    }

    for (int i = 0; i < Q; ++i)
    {
        cin >> str;
        cout << trie.numberOfWords(str) << '\n';
    }

    return 0;
}
