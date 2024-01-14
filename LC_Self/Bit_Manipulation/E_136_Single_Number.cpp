/*

Type: 

Problem: https://leetcode.com/problems/single-number/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=qMPX1AOa83k
*/


/*

A. Bitwise XOR

- XOR of a number with itself cancels out and results in 0.
- For every duplicate number, XOR will cancel it out until only the single number remains.

*/


#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums) {

    int bitXor = 0;

    for (const auto& num : nums) {
        bitXor ^= num;
    }   

    return bitXor;
}

int main() {

    // vector<int> nums = {2,2,1};
    vector<int> nums = {4,1,2,1,2};
    // vector<int> nums = {1};

    cout << singleNumber(nums) << '\n';

    return 0;
}