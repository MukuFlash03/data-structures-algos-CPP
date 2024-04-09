/*

Problem: https://leetcode.com/problems/multiply-strings
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=1vZswirL8Y8
*/


/*

A. Optimal Solution (Recursive)

- Create a vector of size num1.size() + num2.size() to store the result
- Create a tempProd, resInd, carry
- Iterate through num1 and num2 from the end
- resInd is sum of indices of current digits
- Multiply the digits and store the result in result[resInd]
- Iterate through result and add carry
- Create a string answer and iterate through result to store the answer
- Remove any leading zeroes
- Return the answer



*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<unordered_set>

using namespace std;

string multiply(string num1, string num2) {
    vector<int> result(num1.size() + num2.size(), 0);
    int tempProd = 1, resInd = 0, carry = 0;
    int len1 = num1.size(), len2 = num2.size();
    string answer = "";

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            resInd = (len1 - 1 - i) + (len2 - 1 - j);
            tempProd = (num1[i] - '0') * (num2[j] - '0');
            result[resInd] += tempProd;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }

    int i = result.size() - 1;

    while (i >= 0 && result[i] == 0)
        i--;

    if (i == -1)
        return "0";

    while (i >= 0) {
        answer += to_string(result[i]);
        i--;
    }

    return answer;
}

int main() {

    // string num1 = "2", num2 = "3";
    string num1 = "123", num2 = "456";

    cout << multiply(num1, num2) << "\n";

    return 0;
}