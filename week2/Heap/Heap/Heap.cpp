#include "Heap.h"

Heap::Heap()
{

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
//int leftChildIndex = parent * 2 + 1;
//int rightChildIndex = parent * 2 + 2;
//int parent = (index - 1) / 2;
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