#include <iostream>
#include <sstream>
#include "BirthdayRanges.h"

using namespace std;

// Write a function that computes the square root of a number with binary search. Precision of the result should be 0.00001.
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
// 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 5
const int PERCISION = 0.00001;
const int TIMES_TO_LOOP = 128;
int counter = 0;

int floatingDigitsAmount(double number)
{
	bool passedRadix = false;
		int i = 0; // for counting decimals
	std::ostringstream strs;
	strs << number; // dbl is 3.415 or whatever you're counting
	std::string str = strs.str();

	for (char& c : str) {
		if (passedRadix == true)
			i++;
		if (c == '.')
			passedRadix = true;

	}

	return i;
}

double squareRoot(double left, double right, double number)
{
	double middle = left + ((right - left) / 2);
	counter++;
	//double shit = abs((middle * middle) - number);
	if (counter < TIMES_TO_LOOP)
	{
		if (middle * middle < number)
		{
			return squareRoot(middle, right, number);
		}
		else
		{
			return squareRoot(left, middle, number);
		}
	}
	return middle;
}

double getSquareRoot(double number)
{
	return squareRoot(0.0, number, number);
}

int main()
{
	vector<int> cool = { 5, 8, 15, 20, 30, 45, 11, 22, 33, 44 };

	range str1;
	str1.from = 7;
	str1.to = 31;

	range str2;
	str2.from = 10;
	str2.to = 23;

	vector<range> cool1 = {str1, str2};
	vector<int> cool2 = birthdayRanges(cool, cool1);


	return 1;
}