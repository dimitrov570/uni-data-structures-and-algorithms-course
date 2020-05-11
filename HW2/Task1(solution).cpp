#include <iostream>
#include <string>

const int LETTERS_BEGINNING = 97;

bool checkStrings(const std::string &str1, const std::string &str2, int N)
{
    if (N == 0)
    {
        return true;
    }

    if (str1.length() != str2.length())
    {
        return false;
    }

    long long int letters[26];

    for (int i = 0; i < 26; ++i)
    {
        letters[i] = 0;
    }

    for (long long int i = 0; i < str1.length(); ++i) //counting how many times each symbol is used in str1
    {
        letters[str1[i] - LETTERS_BEGINNING]++;
    }

    for (long long int i = 0; i < str1.length(); ++i)
    {
        letters[str2[i] - LETTERS_BEGINNING]--;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (letters[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main() {

    long long int N;
    std::cin >> N;

    std::string str1;
    std::string str2;

    std::cin >> str1;
    std::cin >> str2;

    bool check = checkStrings(str1, str2, N);

    if (check)
    {
        std::cout << "yes";
    }
    else
    {
        std::cout << "no";
    }

    return 0;
}
