#include <iostream>
using namespace std;

void merge(int* arr, int* temp, int left, int middle, int right)
{
	int indexTemp = left;
	int indexLeft = left;
	int indexRight = middle + 1;
	//{1,10,24,47,69, 3,4,15,20,50};
	while (indexLeft <= middle && indexRight <= right)
	{
		if (arr[indexLeft] <= arr[indexRight])
		{
			temp[indexTemp] = arr[indexLeft];
			indexLeft++;
		}
		else
		{
			temp[indexTemp] = arr[indexRight];
			indexRight++;
		}
		indexTemp++;
	}
	if (indexLeft == middle + 1)
	{
		for (indexTemp; indexTemp <= right; indexTemp++)
		{
			temp[indexTemp] = arr[indexRight];
			indexRight++;
		}
	}
	else
	{
		for (indexTemp; indexTemp <= right; indexTemp++)
		{
			temp[indexTemp] = arr[indexLeft];
			indexLeft++;
		}
	}
	for (int i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
}
void mergeSort(int* arr, int* temp, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int middle = (right - left) / 2 + left;

	mergeSort(arr, temp, left, middle);
	mergeSort(arr, temp, middle + 1, right);

	merge(arr, temp, left, middle, right);
}