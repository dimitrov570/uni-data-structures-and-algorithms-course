#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <stdlib.h>

const int ASCII_NUMBERS_BEGINING = 48;
using namespace std;

int main() {

    std::string str;
    getline(std::cin, str);
    
    for (int i = 0; i < str.length(); i++)
    {
        int counter = 1;
        while (str[i] == str[i + 1])
        {
            counter++;
            i++;
        }
        std::cout << counter << str[i];
    }

    return 0;
}
