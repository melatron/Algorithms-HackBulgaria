#include <iostream>
#include "Vector.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;


int main()
{
	Vector<int> vec;

	vec.add(4);
	vec.add(5);
	vec.add(6);
	vec.add(7);
	vec.add(8);
	vec.add(9);

	vec.print();

	int cool = vec.get(200);

	cout << cool;

	return 1;
}