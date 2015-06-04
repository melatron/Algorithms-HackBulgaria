#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */
#include <list>
 
using namespace std;
 
//////////////////////////////////////////////// TASK 1 ///////////////////////////////////////////////
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
 
//////////////////////////////////////////////// TASK 2 ///////////////////////////////////////////////
 
string constructStringFromKey(string key, int length)
{
        string result;
        int keyLength = key.size();
        int timesToAdd = length / keyLength;
        int amount = length % keyLength;
       
        for (int i = 0; i < timesToAdd; i++)
        {
                result += key;
        }
        result += key.substr(0, amount);
 
        return result;
}
 
void printArray(int* arr, int length)
{
        for (int i = 0; i < length; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;
}
 
int* sumTwoArrays(int* arr1, int* arr2, int max, int length)
{
        int* result = new int[length];
        int current = 0;
 
        for (int i = 0; i < length; i++)
        {
                current = arr1[i] + arr2[i];
                if (current < max)
                {
                        result[i] = current;
                }
                else
                {
                        result[i] = current - max;
                }
        }
 
        return result;
}
 
string getStringFromArray(int* arr, string alphabet, int length)
{
        string result = "";
 
        for (int i = 0; i < length; i++)
        {
                result += alphabet[arr[i]];
        }
 
        return result;
}
 
int* getArrayFromString(string original, string alphabet)
{
        int length = original.size() + 1;
        int* result = new int[length];
 
        for (int i = 0; i < length; i++)
        {
                result[i] = alphabet.find(original[i]);
        }
 
        return result;
}
 
void printEncoded(string original, string alphabet, string key)
{
        int* arr = getArrayFromString(original, alphabet);
        printArray(arr, original.size());
}
 
void inputStringKeyAndAlphabet()
{
        string original;
        string alphabet;
        string key;
 
        cout << "Please, enter your string: ";
        getline(std::cin, original);
 
        cout << "Please, enter your alphabet: ";
        getline(std::cin, alphabet);
 
        cout << "Please, enter your key: ";
        getline(std::cin, key);
       
        string stringKey = constructStringFromKey(key, original.size());
        //cout << stringKey << endl;
        int* arr1 = getArrayFromString(original, alphabet);
        //printArray(arr1, original.size());
        int* arr2 = getArrayFromString(stringKey, alphabet);
        //printArray(arr2, original.size());
        int* arr3 = sumTwoArrays(arr1, arr2, alphabet.size(), original.size());
        //printArray(arr3, original.size());
        string newOriginal = getStringFromArray(arr3, alphabet, original.size());
       
        int alphabetSize = alphabet.size();
        int keySize = key.size();
 
        string firstResult = to_string(alphabetSize) + "~" + alphabet + newOriginal + key + "~" + to_string(keySize);
        int halfLength = firstResult.size() / 2;
        string result = "";
 
        for (int i = halfLength; i < firstResult.size(); i++)
        {
                result += firstResult[i];
        }
        for (int i = 0; i < halfLength; i++)
        {
                result += firstResult[i];
        }
        cout << result << endl;
}
 
 
///////////////////////////////// TASK 3 /////////////////////////////////////
 
char getOpositeBracket(char type) {
        switch (type) {
        case '(':
                return ')';
        case ')':
                return '(';
        case '[':
                return ']';
        case ']':
                return '[';
        case '{':
                return '}';
        case '}':
                return '{';
        }
}
 
bool checkIfDigit(char c) {
        return c != '(' && c != ')' && c != '[' && c != ']' && c != '{' && c != '}';
}
 
bool checkIfCorrect(char parentType, char currentType) {
        return parentType == '{' && currentType == '[' || parentType == '[' && currentType == '(';
}
 
int calculateDigits(char* arr, int length){
        int result = 0;
 
        for (int i = 0; i < length; i++) {
                result += (int)(arr[i] - '0') * pow(10, length - i - 1);
        }
 
        return result;
}
//{123[123(123)123(123)]23[123]2}
struct BracketResult {
        int length;
        int calc;
};
 
BracketResult goInBrackets(int index, char type, string input, int length) {
        char opositeType = getOpositeBracket(type);
        int indexDigits = 0;
 
        BracketResult result;
        result.calc = 0;
        result.length = 0;
 
        BracketResult recResult;
        recResult.calc = 0;
        recResult.length = 0;
 
        char* arr = new char[length];
 
        for (int i = index; i < input.size(); i++) {
                if (input[i] == getOpositeBracket(type)) {
                        result.calc += calculateDigits(arr, indexDigits);
                        indexDigits = 0;
                        delete[] arr;
                        result.length = i - index + 1;
                        return result;
                }
                else if (checkIfDigit(input[i])) {
                        arr[indexDigits] = input[i];
                        indexDigits++;
                }
                else {
                        if (!checkIfCorrect(type, input[i])) {
                                result.calc = -1;
                                result.length = -1;
                                return result;
                        }
                        result.calc += calculateDigits(arr, indexDigits);
                        delete[] arr;
                        arr = new char[length];
                        indexDigits = 0;
                        recResult = goInBrackets(i + 1, input[i], input, length);
                        if (recResult.calc == -1 && recResult.length == -1) {
                                result.calc = -1;
                                result.length = -1;
                                return result;
                        }
                        result.calc += 2 * recResult.calc;
                        i += recResult.length;
                }
        }
 
        result.calc = -1;
        result.length = -1;
        return result;
}
 
void inputBrackets() {
        string input;
       
        cout << "Input string with correct brackets: " << endl;
        getline(std::cin, input);
        BracketResult result = goInBrackets(1, input[0], input, input.size());
        if (result.calc == -1 && result.length == -1) {
                cout << "NO" << endl;
        }
        else {
                cout << result.calc;
        }
}
 
 
int main()
{
        // uncomment the function for testing.
        // TAST 1
        //inputStringAndGetPolindromes();
 
        // TAST 2
        //inputStringKeyAndAlphabet();
 
        // TAST 3
        //inputBrackets();
       
        return 1;
}