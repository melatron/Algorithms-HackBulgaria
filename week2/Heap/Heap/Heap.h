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
public:
	Heap();
	~Heap();

	// Accessors and Modifiers
	void Insert(int);
	bool DeleteByValue(int);
	int DeleteByIndex(int index);
	// Utilities
	bool IsEmpty() const;
};

