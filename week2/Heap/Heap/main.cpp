#include <iostream>
#include "Heap.h";

using namespace std;

void heapSort(int* arr, int length)
{
	Heap heap(arr, length);
	int index = 0;

	while (!heap.IsEmpty())
	{
		arr[index] = heap.DeleteByIndex(0);
		index++;
	}
}

int main()
{
	int length = 10;
	int* arr = new int[length]{ 10, 3, 17, 15, 14, 20, 2, -1, 10, 6 };
	heapSort(arr, length);

	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}