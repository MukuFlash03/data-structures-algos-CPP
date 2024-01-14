/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/max-consecutive-ones/
Solution(s): 

YouTube
NC - 
*/

/*

A. Optimal Solution

1. Left pointer tracks start of current sequence of 1s.
2. Right pointer tracks end of current sequence of 1s.
3. Iterate through input nums.
4.  If ith element == 1 => update ans = max(ans, r - l + 1)
5.  Else => l = r + 1
6.  Increment r
7. Return ans

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int l = 0, r = 0;
    int ans = 0;
    while (r < nums.size()) {
        if (nums[r] == 1) {
            ans = max(ans, r - l + 1);
        }
        else {
            l = r + 1;
        }
        r++;
    }
    return ans;
}


int main() {

    vector<int> nums = {1,1,0,1,1,1};
    // vector<int> nums = {1,0,1,1,0,1};

    cout << findMaxConsecutiveOnes(nums) << "\n";

    return 0;
}