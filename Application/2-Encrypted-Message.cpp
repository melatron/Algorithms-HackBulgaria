#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */
#include <list>
 
using namespace std;

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
 

int main()
{
		inputStringKeyAndAlphabet();
       
        return 1;
}