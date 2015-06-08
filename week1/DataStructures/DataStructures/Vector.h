#pragma once

template <typename T>
class Vector
{
private:
	unsigned int size;
	unsigned int capacity;
	T* buffer;

	void doubleCapacity();

public:
	Vector();
	Vector(unsigned int capacity);
	~Vector();

	//Vector<T> & operator=(const Vector<T> &);

	//T & operator[](unsigned int index);
	// Adds value at a specific index in the Vector.
	// Complexity: O(n)
	unsigned int insert(unsigned int index, T value);

	// Adds value to the end of the Vector.
	// Complexity: O(1)
	void add(T value);

	// Returns value at a specific index in the Vector
	// Complexity: O(1)
	T get(unsigned int index);

	// Removes element at the specific index
	// Complexity: O(n)
	T remove(unsigned int index);

	// Removes element at the last index
	// Complexity: O(1)
	T pop();

	// Returns the number of elements in the Vector.
	// Complexity: O(1)
	unsigned int getSize() const;

	// Returns the total capacity of the Vector.
	// Complexity: O(1)
	unsigned int getCapacity() const;

	bool empty() const;

	void print() const;
};

