#include <iostream>
#include <vector>

// level % 2 = 0 -> x
// level % 2 = 1 -> y

struct Node
{
	std::vector<int> point;
	Node *left, *right;
	Node(int x, int y)
	{
		point.push_back(x);
		point.push_back(y);
		left = right = nullptr;
	}
};

class D2tree
{
	Node *root = nullptr;


	Node *insertNode(Node *node, std::vector<int> &p, int level)
	{
		if (node == nullptr)
		{
			return new Node{ p[0], p[1] };
		}
		int coord = level % 2;
		if (p[coord] < node->point[coord])	//left
		{
			node->left = insertNode(node->left, p, level + 1);
		}
		else
		{
			node->right = insertNode(node->right, p, level + 1);
		}
		return node;
	}

	/*
	void insertNode(Node *node, std::vector<int> &p, int level)
	{

		int coord = level % 2;
		if (p[coord] < node->point[coord])	//left
		{
			if (node->left == nullptr)
			{
				node->left = new Node(p);
				return;
			}
			insertNode(node->left, p, level + 1);
		}
		else	//right
		{
			if (node->right == nullptr)
			{
				node->right = new Node(p);
				return;
			}
			insertNode(node->right, p, level + 1);
		}
	}
	*/

	void printTree(Node *node)
	{
		if (node == nullptr)
		{
			return;
		}
		printTree(node->left);
		std::cout << " " << node->point[0] << "," << node->point[1] << " ";
		printTree(node->right);
	}

public:
	void insert(int x, int y)
	{
		std::vector<int> p;
		p.push_back(x);
		p.push_back(y);

		if (root == nullptr)
		{
			root = new Node{ p[0], p[1] };
			return;
		}
		insertNode(root, p, 0);
	}

	void print()
	{
		printTree(root);
	}

};

int main()
{
	D2tree tree;
	tree.insert(3, 4);
	tree.insert(1, 2);
	tree.insert(4, 1);
	tree.insert(-1, 2);
	tree.insert(13, 8);
	tree.insert(-2, 1);
	tree.insert(2, 1);
	tree.insert(9, 9);
	tree.insert(2, 3);
	tree.print();

	return 0;
}
