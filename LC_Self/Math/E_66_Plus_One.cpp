/*

Problem: https://leetcode.com/problems/plus-one
Solution(s): 

YouTube
NC - 
*/


/*

A. Optimal Solution

- Implement normal addition operation.
- If carry exists, handle accordingly.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<unordered_set>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int carry = 0;
    int addend = 1;
    int sum = 0;

    for (int i = digits.size() - 1; i >= 0; i--) {
        sum = digits[i] + addend;
        carry = sum / 10;
        digits[i] = sum % 10;

        if (carry != 1)
            break;
        else {
            addend = carry;
            if (i == 0)
                digits.insert(digits.begin(), 1);
        }
    }

    return digits;

}

int main() {

    vector<int> digits = {1,2,3};
    // vector<int> digits = {4,3,2,1};
    // vector<int> digits = {9};

    cout << plusOne(digits) << "\n"; 

    return 0;
}