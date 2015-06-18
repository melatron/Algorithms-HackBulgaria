#pragma once

#include <vector>
#include <string>

using namespace std;

class Contact {
public:
	string name;
	int number;
};


class PhoneBook {
private:
	string findNumber(vector<Contact> phoneBook, int numbers, int left, int right);
public:

	// Find the names of people based on their phone numbers.
	vector<string> lookupNames(vector<Contact> phoneBook, vector<int> numbers);
};