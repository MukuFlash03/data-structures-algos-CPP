/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
https://www.youtube.com/watch?v=p-ss2JNynmw

Problem: https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/
Solution(s): https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/
- https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/solutions/937272/java-longest-subarray-sum-equal-to-k/

YouTube
NC - 

A. Sliding Window (Basic Concept - Optimal)

1. Outer loop:  Iterate from start till end with both pointers starting at 0
2.  Calculate sum of all elements upto current end pointer
3.  Increment end pointer
4.  Inner loop: Iterate while start < end and sum > target
5.      Keep removing elements from start pointer
6.      Increment start pointer
7. If sum == target, update max length
8. Return max length

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


int longestSubarrayWithSumK(vector<int>& nums, int target) {
    int maxLen = INT_MIN;
    int currSum = 0;
    int start = 0, end = 0;

    while (end < nums.size()) {
        currSum += nums[end];

        while (start < end && currSum > target) {
            currSum -= nums[start];
            start++;
        }

        if (currSum == target) {
            maxLen = max(maxLen, end-start+1);
        }
        end++;
    }

    if (maxLen == INT_MIN)
        return 0;

    return maxLen;   
}


int main() {
    vector<int> nums = {1,2,3,1,1,1,1};
    int target = 3;

    // vector<int> nums = {1,2,1,3};
    // int target = 2;

    // vector<int> nums = {2,2,4,1,2};
    // int target = 2;

    // vector<int> nums = {8,15,17,0,11};
    // int target = 17;

    // vector<int> nums = {1,1,0,1,1};
    // int target = 2;


    int maxLen = longestSubarrayWithSumK(nums, target);
    cout << "Max. length sum subarray = " << maxLen << endl;

    return 0;
}
