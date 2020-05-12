#include <iostream>
#include <string>
#include <map>

using namespace std;
struct Node
{
    Node* parent;
    string name;
    map<string, Node*> subDirectories;

    Node(Node* parent, const string name)
    {
        this->parent = parent;
        this->name = name;
    }
};


class FileSystem
{
    Node* current;

    void showPathRecursive(Node *tmp)
    {
        if (tmp == nullptr)
        {
            return;
        }
        showPathRecursive(tmp->parent);
        cout << tmp->name << "/";
    }

public:
    FileSystem()
    {
        current = new Node(nullptr, "");
    }

    void addDirectory(const string name)
    {
        if (current->subDirectories[name] != NULL)
        {
            cout << "Directory already exists\n";
        }
        else
        {
            current->subDirectories[name] = new Node(current, name);
        }
    }

    void listCurrentDirectories()
    {
        for (auto it = current->subDirectories.begin(); it != current->subDirectories.end(); ++it)
        {
            cout << it->first << " ";
        }
        cout << '\n';
    }

    void showPath()
    {
        showPathRecursive(current);
        cout << '\n';
    }

    void changeDirectory(const string name)
    {
        if (name == "..")
        {
            if (current->parent != nullptr)
            {
                current = current->parent;
            }
            else
            {
                cout << "No such directory\n";
            }
        }
        else if (current->subDirectories[name])
        {
            current = current->subDirectories[name];
        }
        else
        {
            cout << "No such directory\n";
        }
    }

};

int main()
{
    int N;
    cin >> N;

    FileSystem fs;

    string command;
    string name;

    for (int i = 0; i < N; ++i)
    {
        cin >> command;
        if (command == "mkdir")
        {
            cin >> name;
            fs.addDirectory(name);
        }
        else if (command == "cd")
        {
            cin >> name;
            fs.changeDirectory(name);
        }
        else if (command == "ls")
        {
            fs.listCurrentDirectories();
        }
        else if (command == "pwd")
        {
            fs.showPath();
        }
    }

    return 0;
}
