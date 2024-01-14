/*

Type: 

Problem: https://leetcode.com/problems/missing-number/
Solution(s): 
- https://www.geeksforgeeks.org/find-the-missing-number/

YouTube
NC - https://www.youtube.com/watch?v=WnPLSRLSANE
*/


/*

A. Bitwise Operations

- XOR of a number with itself is 0.
- XOR of a number with 0 is number itself.
- XOR of a sequential series of numbers = A.
- XOR of same sequence with a missing numbers = B.
- XOR of A and B = missing number.

B. Sum of Natural Numbers

- Calculate sum of natural numbers from 1 to n.
- Calculate sum of numbers in array.
- Subtract the two to get the missing number.
- Might have overflow issues.

*/



#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int>& nums) {

    int a = 0, b = 0;
    // int a = 0, b = nums[0];

    // for (int i = 1; i <= nums.size(); i++)
    //     a ^= i;

    // for (int i = 1; i < nums.size(); i++)
    for (int i = 0; i < nums.size(); i++) {
        b ^= nums[i];
        a ^= (i + 1); // Ignore when using b = nums[0]
    }

    return a ^ b;
}

int missingNumberSum(vector<int>& nums) {
    int a = 0, b = 0;
    int n = nums.size();

    a = n * (n+1) / 2;

    for (int i = 0; i < nums.size(); i++)
        b += nums[i];

    return a - b;
}

int main() {

    vector<int> nums = {3,0,1};
    // vector<int> nums = {0,1};
    // vector<int> nums = {9,6,4,2,3,5,7,0,1};

    cout << missingNumber(nums) << '\n';

    return 0;
}