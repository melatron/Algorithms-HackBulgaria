#include <iostream>
using namespace std;

int pivot(int* arr, int left, int right)
{
	int k = left;
	int last = arr[right];

	for (int i = left; i < right; i++)
	{
		if (arr[i] < last)
		{
			swap(arr[i], arr[k]);
			k++;
		}
	}
	swap(arr[right], arr[k]);
	return k;
}

void quickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int p = pivot(arr, left, right);
		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);
	}
	return;
}



//[0,1,2,3,4,5,6,7,8,9,10]
//{6, 9, 10, 4, 7, 2, 1, 5}