#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int Data)
    {
        data = Data;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
    Node* root;

public:
    BST()
    {
        root = nullptr;
    }

    void addNode(int data)
    {
        if (root == nullptr)
        {
            root = new Node{ data };
        }
        else
        {
            Node* current = root;
            while (current != nullptr)
            {
                if (current->data == data)
                {
                    return;
                }
                else if (current->data < data)
                {
                    if (current->right == nullptr)
                    {
                        current->right = new Node{ data };
                        current = nullptr;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
                else if (current->data > data)
                {
                    if (current->left == nullptr)
                    {
                        current->left = new Node{ data };
                        current = nullptr;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
            }
        }

    }

    int findPositionOfElement(int data)
    {
        Node*current = root;
        int position = -1;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                return position + 1;
            }
            else if (current->data < data)
            {
                current = current->right;
                ++position;
            }
            else
            {
                current = current->left;
                ++position;
            }
        }
        return -1;
    }

};


int main()
{
    int N, K;
    std::cin >> N >> K;

    BST city;

    int data;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> data;
        city.addNode(data);
    }

    int *addresses = new int[K];

    for (int i = 0; i < K; ++i)
    {
        std::cin >> addresses[i];
    }

    for (int i = 0; i < K; ++i)
    {
        std::cout << city.findPositionOfElement(addresses[i]) << std::endl;
    }
    return 0;
}
