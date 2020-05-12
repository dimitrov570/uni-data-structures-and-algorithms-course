#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
    double value;
    int height;
    Node *left;
    Node *right;

    Node(double value, int height = 1, Node *left = nullptr, Node *right = nullptr)
    {
        this->value = value;
        this->height = height;
        this->left = left;
        this->right = right;
    }
};

class AVLTree
{
private:
    Node *root = nullptr;

    bool containsRecursive(Node *current, double value)
    {
        if (current == nullptr)
        {
            return false;
        }

        if (current->value == value)
        {
            return true;
        }

        if (value < current->value)
        {
            return containsRecursive(current->left, value);
        }
        else
        {
            return containsRecursive(current->right, value);
        }
    }

    void printRecursive(Node *current)
    {
        if (current == NULL)
        {
            return;
        }

        printRecursive(current->left);
        cout << current->value << " ";
        printRecursive(current->right);
    }

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return node->height;
        }
    }

    void correctHeight(Node *node)
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight < rightHeight)
        {
            node->height = rightHeight + 1;
        }
        else
        {
            node->height = leftHeight + 1;
        }
    }

    int balanceFactor(Node *node)
    {
        return height(node->left) - height(node->right);
    }

    Node *leftRotation(Node *node)
    {
        Node *rightNode = node->right;
        node->right = rightNode->left;
        rightNode->left = node;
        correctHeight(node);
        correctHeight(rightNode);
        return rightNode;
    }

    Node *rightRotation(Node *node)
    {
        Node *leftNode = node->left;
        node->left = leftNode->right;
        leftNode->right = node;
        correctHeight(node);
        correctHeight(leftNode);
        return leftNode;
    }

    Node* balance(Node *node)
    {
        correctHeight(node);
        if (balanceFactor(node) == -2)
        {
            if (balanceFactor(node->right) > 0)
            {
                node->right = rightRotation(node->right);
            }
            return leftRotation(node);
        }
        else if (balanceFactor(node) == 2)
        {
            if (balanceFactor(node->left) < 0)
            {
                node->left = leftRotation(node->left);
            }
            return rightRotation(node);
        }
        return node;
    }

    Node *addNode(Node *node, double value)
    {
        if (node == nullptr)
        {
            return new Node{ value };
        }
        else if (node->value < value)
        {
            node->right = addNode(node->right, value);
        }
        else if (node->value > value)
        {
            node->left = addNode(node->left, value);
        }
        return balance(node);
    }

    Node* findMinNode(Node *node)
    {
        if (node != nullptr)
        {
            while (node->left != nullptr)
            {
                node = node->left;
            }
        }
        return node;
    }

    Node* removeMinNode(Node *node)
    {
        if (node->left == nullptr)
        {
            return node->right;
        }
        node->left = removeMinNode(node->left);
        return balance(node);
    }

    Node* removeNode(Node* node, double value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->value == value)
        {
            Node *min = findMinNode(node->right);
            Node *leftRoot = node->left;
            Node *rightRoot = node->right;
            delete node;
            if (rightRoot == nullptr)
            {
                return leftRoot;
            }
            min->right = removeMinNode(rightRoot);
            min->left = leftRoot;
            return balance(min);
        }
        else if (node->value < value)
        {
            node->right = removeNode(node->right, value);
        }
        else
        {
            node->left = removeNode(node->left, value);
        }
        return balance(node);
    }

public:
    AVLTree()
    {
        root = NULL;
    }

    void add(double value)
    {
        if (contains(value))
        {
            std::cout << value << " already added" << std::endl;
        }
        else
        {
            root = addNode(root, value);
        }
    }

    void remove(double value)
    {
        if (!contains(value) || root == nullptr)
        {
            std::cout << value << " not found to remove" << std::endl;
        }
        else
        {
            root = removeNode(root, value);
        }
    }

    bool contains(double value)
    {
        if (root == NULL)
        {
            return false;
        }

        return containsRecursive(root, value);
    }

    void print()
    {
        if (root == NULL)
        {
            return;
        }

        printRecursive(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;
    string operation;
    double number;
    int N;

    cin >> N;
    cout << fixed;

    for (size_t i = 0; i < N; i++)
    {
        cin >> operation;
        if (operation != "print")
        {
            cin >> number;
        }

        if (operation == "add")
        {
            tree.add(number);
        }
        else if (operation == "remove")
        {
            tree.remove(number);
        }
        else if (operation == "contains")
        {
            if (tree.contains(number))
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (operation == "print")
        {
            tree.print();
        }
    }

    return 0;
}
