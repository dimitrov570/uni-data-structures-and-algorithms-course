#include <iostream>

int main() {
    int T;
    long int copies, originals;

    std::cin >> T;

    bool *answers = new bool[T];

    int i = 0;
    while (i < T)
    {
        std::cin >> copies >> originals;
        if (originals < 1 || (copies + 1) < originals)
        {
            answers[i++] = false;
        }
        else if (originals == 1 && copies > 0)
        {
            answers[i++] = false;
        }
        else if ((copies - originals) % 2 != 0)
        {
            answers[i++] = true;
        }
        else
        {
            answers[i++] = false;
        }
    }

    for (int i = 0; i < T; ++i)
    {
        if (answers[i] == true)
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }

    delete[] answers;

    return 0;
}
