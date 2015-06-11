#include <iostream>
using namespace std;

int kthDigit(int x, int k) {
	int temp = (int)(pow(10, k - 1));
	return (x / temp) % 10;
}

void countingSort(int* arr, int length, int digit)
{
	int helpArr[10] = { 0 };
	int* container = new int[length];
	for (int i = 0; i < length; i++)
	{
		helpArr[kthDigit(arr[i], digit)]++;
	}
	helpArr[0]--;
	for (int i = 0; i < 9; i++)
	{
		helpArr[i + 1] += helpArr[i];
	}
	// 
	for (int i = length - 1; i >= 0; i--)
	{
		container[helpArr[kthDigit(arr[i], digit)]] = arr[i];
		helpArr[kthDigit(arr[i], digit)]--;
	}
	for (int i = 0; i < length; i++)
	{
		arr[i] = container[i];
	}
	delete[] container;
}
void RadixSort(int* arr, int length, int mostDigits)
{
	for (int i = 1; i <= mostDigits; i++)
	{
		countingSort(arr, length, i);
	}
}