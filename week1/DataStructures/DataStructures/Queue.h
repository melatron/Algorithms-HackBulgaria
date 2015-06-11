#pragma once

#include "Vector.h";

template <typename T>
class Queue
{
private:
	Vector<T> container;
public:
	Queue();
	~Queue();

	// Adds value to the end of the Queue.
	// Complexity: O(1)
	void push(value);

		// Returns value from the front of the Queue and removes it.
		// Complexity: O(1)
	T pop();

		// Returns value from the front of the Queue without removing it.
		// Complexity: O(1)
	T peek() const;

		// Returns the number of elements in the Queue.
		// Complexity: O(1)
	unsigned int size() const;
};
