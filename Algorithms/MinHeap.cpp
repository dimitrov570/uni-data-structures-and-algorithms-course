#include <iostream>
#include <vector>
#include <stdio.h>

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

class minHeap {
	std::vector<int> vector;
	int size;

	int leftChildIndex(int index)
	{
		return index * 2 + 1;
	}

	int rightChildIndex(int index)
	{
		return index * 2 + 2;
	}

	int parentIndex(int index)
	{
		return (index - 1) / 2;
	}

	bool hasLeftChild(int index)
	{
		return leftChildIndex(index) < size;
	}

	bool hasRightChild(int index)
	{
		return rightChildIndex(index) < size;
	}

	bool hasParent(int index)
	{
		return parentIndex(index) >= 0;
	}

	void push(int number)
	{
		vector.push_back(number);
		siftUp();
	}

	void pop()
	{
		if (vector.size() == 0)
		{
			return;
		}
		else
		{
			swap(vector[0], vector[vector.size() - 1]);
			vector.pop_back();
			siftDown();
		}
	}

	int top()
	{
		if (!vector.empty())
		{
			return vector[0];
		}
		return INT_MIN;
	}

	void siftUp()
	{
		int index = vector.size() - 1;
		while (hasParent(index) && vector[parentIndex(index)] > vector[index])
		{
			swap(vector[parentIndex(index)], vector[index]);
			index = parentIndex(index);
		}
	}

	void siftDown()
	{
		int index = 0;
		int minChildIndex;
		while (hasLeftChild(index))
		{
			minChildIndex = leftChildIndex(index);
			if (hasRightChild(index))
			{
				if (vector[rightChildIndex(index)] < vector[minChildIndex])
				{
					minChildIndex = rightChildIndex(index);
				}
			}
			if (vector[index] <= vector[minChildIndex])
			{
				return;
			}
			else
			{
				swap(vector[index], vector[minChildIndex]);
				index = minChildIndex;
			}
		}
	}
};
