/*

Problem: https://leetcode.com/problems/move-zeroes/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=aayNRwUN3Do
*/


/*

A. Brute Force

1. Iterate through the list.
2. Store all non-zero elements in a list.
3. Store all zero elements in a list.
4. Concatenate the two lists.

B. Optimal Solution (Two Pointer)

1. Iterate through the list.
2. If current element is not 0, swap it with the element at the index of the second pointer.
3. Increment second pointer.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


// Soln A
void moveZeroesA(vector<int>& nums) {
    int count = 0;
    vector <int> pos;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != 0)
            pos.push_back(nums[i]);
    
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == 0)
            pos.push_back(0);
    
    for (int i = 0; i < nums.size(); i++)
        nums[i] = pos[i];
}

// Soln B

void moveZeroes(vector<int>& nums) { 
    int l = 0, r = 0;
    
    while (r < nums.size()) { 
        if (nums[r] != 0) {
            swap(nums[l], nums[r]);
            l++;
        }
        r++;
    }
}

int main() {

    vector<int> nums = {0,1,0,3,12};
    // vector<int> nums = {0};

    moveZeroes(nums);

    for (const int &elem : nums)
        cout << elem << '\t';
    cout << '\n';

    return 0;
}