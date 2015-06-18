#include <vector>
#include <string>
#include <algorithm>
#include "PhoneBook.h"

using namespace std;

vector<string> PhoneBook::lookupNames(vector<Contact> phoneBook, vector<int> numbers)
{
	vector<string> result;

	sort(phoneBook.begin(), phoneBook.end(), [&](Contact a, Contact b)->bool{return a.number < b.number; });

	for (int number : numbers)
	{
		string current = this->findNumber(phoneBook, numbers[number], 0, phoneBook.size());

		if (current != "")
		{
			result.push_back(current);
		}
	}

	return result;
}

string PhoneBook::findNumber(vector<Contact> phoneBook, int number, int left, int right)
{
	int middle = left + ((right - left) / 2);
	if (left >= right)
	{
		return "";
	}
	else if (phoneBook[middle].number == number) {
		return phoneBook[middle].name;
	}
	else if (phoneBook[middle].number < number){
		return this->findNumber(phoneBook, number, middle + 1, right);
	}
	else
	{
		return this->findNumber(phoneBook, number, left, middle - 1);
	}
}