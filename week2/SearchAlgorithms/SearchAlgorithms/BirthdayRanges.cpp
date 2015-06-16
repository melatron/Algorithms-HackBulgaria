#include <iostream>
#include <algorithm>
#include <vector>
#include "BirthdayRanges.h"
using namespace std;
// Given a vector of people's birthdays (numbers in the range 0-365) and a vector of ranges
//(pairs of numbers in the range 0-365) produce a vector of the number of people with birthday in the specific range.


// 1 3 4 6 9 10 15 18 29 49 69 120
// 6-30

int fromLargerThan(int left, int right, int number, vector<int> &birhtdays)
{
	int middle = left + ((right - left) / 2);
	if (left >= right)
	{
		return left;
	} 
	else
	{
		if (birhtdays[middle] >= number)
		{
			return fromLargerThan(left, middle, number, birhtdays);
		}
		else
		{
			return fromLargerThan(middle + 1, right, number, birhtdays);
		}
	}
}
// 1 3 4 6 9 10 15 18 29 49 69 120
// 0 1 2 3 4 5  6  7  8  9  10  11
// 6-30
int getBirthdaysInRange(range r, vector<int> &birthdays)
{
	int length = birthdays.size() - 1;
	int left = fromLargerThan(0, length, r.from, birthdays);
	int right = fromLargerThan(0, length, r.to, birthdays);

	return right - left > 0 ? right - left : 0;
}

vector<int> birthdayRanges(vector<int> birthdays, vector<range> ranges)
{
	std::sort(birthdays.begin(), birthdays.end());
	vector<int> result;

	for (range range : ranges)
	{
		result.push_back(getBirthdaysInRange(range, birthdays));
	}

	return result;
}