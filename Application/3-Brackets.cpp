#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */
#include <list>
 
using namespace std;

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

int main()
{
        inputBrackets();
       
        return 1;
}