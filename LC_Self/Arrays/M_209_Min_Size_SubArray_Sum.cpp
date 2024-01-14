/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
https://www.youtube.com/watch?v=p-ss2JNynmw

Problem: https://leetcode.com/problems/minimum-size-subarray-sum/
Solution(s): https://leetcode.com/problems/minimum-size-subarray-sum/solutions/127732/minimum-size-subarray-sum/

YouTube
NC - https://www.youtube.com/watch?v=aYqYMIqZx5s


A. Sliding Window (Basic Concept - Optimal)

1. Outer loop:  Iterate from start till end with both pointers starting at 0
2.  Calculate sum of all elements upto current end pointer
3.  Increment end pointer
4.  Inner loop: Iterate while start < end and sum >= target
5.      Keep removing elements from start pointer
6.      Increment start pointer

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = INT_MAX;
    int currSum = 0;
    int start = 0, end = 0;

    while (end < nums.size()) {
        currSum += nums[end];
        end++;

        while (start < end && currSum >= target) {
            currSum -= nums[start];
            start++;

            minLen = min(minLen, end-start+1);
        }
    }

    if (minLen == INT_MAX)
        return 0;

    return minLen;   
}


int main() {    
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    // vector<int> nums = {1,4,4};
    // int target = 4;

    // vector<int> nums = {1,1,1,1,1,1,1,1};
    // int target = 11;


    int minLen = minSubArrayLen(, nums);
    cout << "Min. length sum subarray = " << minLen << endl;

    return 0;
}