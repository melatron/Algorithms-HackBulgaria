#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
	vector<int> container;
	void SiftUp(int index);
	void SiftDown(int index);
	int getParentIndex(int index);
	int getLeftChildIndex(int index);
	int getRightChildIndex(int index);
	int Find(int value, int index);
public:
	Heap();
	Heap(int*, int);
	~Heap();

	// Accessors and Modifiers
	void Insert(int);
	bool DeleteByValue(int);
	int DeleteByIndex(int index);
	int Find(int value);
	// Utilities
	bool IsEmpty() const;
};

