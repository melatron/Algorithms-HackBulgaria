#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */
#include <list>
 
using namespace std;
 
void rotate(string &s)
{
        for (int i = 1; i < s.size(); i++)
        {
                swap(s[i - 1], s[i]);
        }
}
 
bool checkIfPalindrome(string s)
{
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}
 
void printAllPalindromes(string s)
{
        int counter = 0;
 
        for (int i = 0; i < s.size(); i++)
        {
                if (checkIfPalindrome(s))
                {
                        counter++;
                        cout << s << endl;
                }
                rotate(s);
        }
 
        if (counter == 0)
        {
                cout << "NONE" << endl;
        }
}
 
void inputStringAndGetPolindromes()
{
        string name;
 
        cout << "Please, enter your string: ";
        getline(cin, name);
        printAllPalindromes(name);
}

int main()
{
        inputStringAndGetPolindromes();
       
        return 1;
}