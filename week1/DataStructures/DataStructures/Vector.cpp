#include "Vector.h"

template <typename T>
Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 10;
	this->buffer = new T[this->capacity];
}

template <typename T>
Vector<T>::Vector(unsigned int newCapacity)
{
	this->size = 0;
	this->capacity = newCapacity;
	this->buffer = new T[this->capacity];
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] this->buffer;
}

template <typename T>
void Vector<T>::doubleCapacity() {
	T* newBuffer = new T[this->capacity * 2];

	for (unsigned int i = 0; i < this->capacity; i++)
	{
		newBuffer[i] = this->buffer[i];
	}
	delete[] this->buffer;

	this->buffer = newBuffer;

	this->capacity *= 2;
}

template <typename T>
void Vector<T>::add(T value)
{
	if (! (this->size < this->capacity))
	{
		this->doubleCapacity();
	}
	this->buffer[this->size] = value;
	this->size++;
}

template <typename T>

unsigned int Vector<T>::insert(unsigned int index, T value)
{
	if (index <= this->size)
	{
		if (this->size == this->capacity)
		{
			this->doubleCapacity();
		}

		T* newBuffer = new T[this->capacity];
		int mar = 0;

		for (unsigned int i = 0; i < this->size; i++)
		{
			if (i == index)
			{
				newBuffer[i] = value;
				mar += 1;
			}

			newBuffer[i + mar] = this->buffer[i];
		}

		delete[] this->buffer;
		this->buffer = newBuffer;
		this->size++;

		return index;
	}
	else
	{
		return -1;
	}
}

template <typename T>
T  Vector<T>::get(unsigned int index)
{
	if (index < this->size && index >= 0)
	{
		return this->buffer[index];
	}

	return NULL;
}

// Removes element at the specific index
template <typename T>
T  Vector<T>::remove(unsigned int index)
{
	if (index < this->size && index >= 0) 
	{
		T element = this->buffer[index];

		for (int i = index + 1; i < this->size; i++)
		{
			this->buffer[i - 1] = this->buffer[i];
		}

		this->size--;

		return element;
	}
	return NULL;
}

// Removes element at the last index
template <typename T>
T  Vector<T>::pop()
{
	T element = this->buffer[this->size - 1];
	
	this->size--;
	return element;
}

// Returns the number of elements in the Vector.
template <typename T>
unsigned int  Vector<T>::getSize() const
{
	return this->size;
}

// Returns the total capacity of the Vector.
template <typename T>
unsigned int  Vector<T>::getCapacity() const
{
	return this->capacity;
}

template <typename T>
bool  Vector<T>::empty() const
{
	return this->size == 0;
}

template <typename T>
void Vector<T>::print() const
{
	cout << "size: " << this->size << " capacity: " << this->capacity << endl;
	for (unsigned int i = 0; i < size; i++)
	{
		cout << this->buffer[i] << ' ';
	}
	return;
}