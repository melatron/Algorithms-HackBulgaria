#include "CountSort.h";
#include "MergeSort.h";
#include "QuickSort.h";
#include "InsertionSort.h";
#include "SelectionSort.h";

#include <iostream>;

using namespace std;

void printArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() 
{
	int arr[8] = {6, 9, 10, 4, 7, 2, 1, 5};
	int arr1[8];

	//mergeSort(arr, arr1, 0, 7);
	//quickSort(arr, 0, 7);
	//selectionSort(arr, 8);
	//insertionSort(arr, 8);
	//countSort(arr, 8);
	
	printArray(arr, 8);

	return 1;
}