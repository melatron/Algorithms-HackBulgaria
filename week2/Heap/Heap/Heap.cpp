#include "Heap.h"

Heap::Heap()
{

}

Heap::Heap(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		this->Insert(arr[i]);
	}
}

Heap::~Heap()
{
}

bool Heap::IsEmpty() const
{
	return this->container.empty();
}
// 1 9 4 7 3 5 6 2 8 0
// 0 1 2 3 4 5 6 7 8 9
int Heap::getParentIndex(int index)
{
	return (index - 1) / 2;
}

int Heap::getLeftChildIndex(int parent)
{
	return parent * 2 + 1;
}

int Heap::getRightChildIndex(int parent)
{
	return parent * 2 + 2;
}

void Heap::SiftUp(int index)
{
	if (index > 0)
	{
		int parent = this->getParentIndex(index);

		if (this->container[parent] > this->container[index])
		{
			swap(this->container[parent], this->container[index]);
			this->SiftUp(parent);
		}
	}
}

void Heap::SiftDown(int parent)
{
	int leftChildIndex = this->getLeftChildIndex(parent);
	int rightChildIndex = this->getRightChildIndex(parent);
	int lowerChildIndex;

	if (leftChildIndex < this->container.size())
	{
		lowerChildIndex = leftChildIndex;
		if (rightChildIndex < this->container.size() && this->container[rightChildIndex] < this->container[leftChildIndex])
		{
			lowerChildIndex = rightChildIndex;
		}

		if (this->container[parent] > this->container[lowerChildIndex])
		{
			swap(this->container[parent], this->container[lowerChildIndex]);
			this->SiftDown(lowerChildIndex);
		}
	}
}

// Accessors and Modifiers
void Heap::Insert(int value)
{
	this->container.push_back(value);
	this->SiftUp(container.size() - 1);
}
bool Heap::DeleteByValue(int value)
{
	int searchedIndex = this->Find(value);
	if (searchedIndex != -1)
	{
		this->DeleteByIndex(searchedIndex);
		return true;
	}
	else
	{
		return false;
	}
}

int Heap::Find(int value, int index)
{
	if (index >= this->container.size())
	{
		return -1;
	}
	else if (this->container[index] == value)
	{
		return index;
	}
	else
	{
		int leftChildIndex = this->getLeftChildIndex(index);
		int rightChildIndex = this->getRightChildIndex(index);

		if (leftChildIndex < this->container.size())
		{
			return this->Find(value, leftChildIndex);

			if (rightChildIndex < this->container.size())
			{
				return this->Find(value, rightChildIndex);
			}
		}
	}
}

int Heap::Find(int value)
{
	return this->Find(value, 0);
}

int Heap::DeleteByIndex(int index)
{
	int current = this->container[index];
	this->container[index] = this->container[this->container.size() - 1];
	this->container.pop_back();
	this->SiftDown(index);
	return current;
}