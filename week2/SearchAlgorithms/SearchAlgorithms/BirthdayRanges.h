#pragma once

#include <vector>
using namespace std;

typedef struct
{
	int from;
	int to;
} range;

vector<int> birthdayRanges(vector<int> birthdays, vector<range> ranges);