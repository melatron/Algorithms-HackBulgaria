#include "Queue.h"

template <typename T>
void Queue<T>::push(T value)
{
	this->container.add(value);
}

// Returns value from the front of the Queue and removes it.
// Complexity: O(1)
template <typename T>
T Queue<T>::pop()
{
	return this->container.remove(0);
}

// Returns value from the front of the Queue without removing it.
// Complexity: O(1)
template <typename T>
T Queue::peek() const
{
	return this->container.get()
}

// Returns the number of elements in the Queue.
// Complexity: O(1)
template <typename T>
unsigned int Queue::size() const
{

}
