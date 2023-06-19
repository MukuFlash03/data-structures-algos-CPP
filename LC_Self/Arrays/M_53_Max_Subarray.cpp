/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Precomputation (Pre-Postfix)

Problem: https://leetcode.com/problems/maximum-subarray/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=5WZl3MMT0Eg



Brute Force: O(n^3) -> Find all subarrays;
            i = f(0,n-1), j = f(i,n-1); k = f(i,j)
Pre-Optimimal: O(n^2) -> Maintain sum of previous subarray and add only new element;
            i = f(0,n-1), j = f(i,n-1); currSum + num[j]

Optimal: We don't have to start at every single value in the array 
to compute every single subarray as we are trying to find maximum subarray.

A. Sliding Window (Optimal)

- Any time we encounter negative prefix value, remove the value by moving left pointer to the left.
- Else keep moving to the right.

Note: Negative prefix value essentially refers to current computed sum upto the ith element (not including ith element)


Steps:
- Iterate through list linearly
- If current sum is -ve, reset it to 0
- Add current element to current sum
- Fetch maximum value of maximum and current sum


Worst case scenario:
- If it is all -ve numbers in list, at any time, we will be storing only one -ve element.
- Since for every ith element, current sum will be checked and in this case, 
its negativity will increase with each new element.
- Thus every time, current sum will be reset and only the current value will be stored in current sum.
- Finally, maximum will be computed and returned.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


int maxSubArray(vector<int>& nums) {

    int maxSum = nums[0];
    int currSum = 0;

    for (const int &elem : nums) {
        if (currSum < 0)
            currSum = 0;
        currSum += elem;
        maxSum = max(maxSum,currSum);
    }

    return maxSum;
}


int main() {

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> nums = {5,4,-1,7,8};
    // vector<int> nums = {1};
    // vector<int> nums = {-4,-5,-3};
    
    int maxSum = maxSubArray(nums);
    cout << maxSum << "\n";

    return 0;
}