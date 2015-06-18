#include <iostream>
#include <algorithm>
using namespace std;

int* twoArrayCombinations(int* firstArr, int* secondArr, int firstLength, int secondLength)
{
	int* result = new int[firstLength * secondLength];
	int index = 0;

	for (int i = 0; i < firstLength; i++)
	{
		for (int j = 0; j < secondLength; j++)
		{
			result[index] = firstArr[i] + secondArr[j];
			index++;
		}
	}

	return result;
}

int countZeroCOmbinations(int* firstArr, int* secondArr, int length)
{
	int j = 0;
	int i = 0;
	int counter = 0;
	int currentSum = 0;

	while (i < length && j < length)
	{
		currentSum = firstArr[i] + secondArr[j];
		if (currentSum == 0)
		{
			int sameIAmount = 1;
			int sameJAmount = 1;
			int sameI = i + 1;
			int sameJ = j + 1;

			while (sameI < length && firstArr[sameI] == firstArr[i])
			{
				sameIAmount++;
				sameI++;
			}
			while (sameJ < length && secondArr[sameJ] == secondArr[j])
			{
				sameJAmount++;
				sameJ++;
			}
			counter += sameJAmount * sameIAmount;
			i = sameI;
			j = sameJ;
		}
		else if (currentSum > 0)
		{
			j++;
		}
		else {
			i++;
		}
	}

	return counter;
}

int quadruplets(int* arr1, int* arr2, int* arr3, int* arr4, int length)
{
	int* combinedArr1 = twoArrayCombinations(arr1, arr2, length, length);
	int* combinedArr2 = twoArrayCombinations(arr3, arr4, length, length);

	sort(combinedArr1, combinedArr1 + (length * length));

	sort(combinedArr2, combinedArr2 + (length * length), [](int a, int b)->bool{return a > b;});

	return countZeroCOmbinations(combinedArr1, combinedArr2, (length * length));
}