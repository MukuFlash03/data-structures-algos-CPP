/*
Type: Binary Search
Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=nIVW4P8b1VA
*/


/*

A. Binary Search [O(logn) required]

The array is divided into two sorted lists.
Binary search has three pointers: L,M,R; with L <= R always satisfied.

How to check which portion of array we are in?
- If L <= M, then we are in left subarray as M is part of Left subarray

Assuming that mid is in left sorted subarray and we know we are in left sorted subarray
- All elements to the left of mid can be discarded 
    - Set new L = M + 1
- All elements to the right of mid will be in sorted order since element at L < element at R
- Find minimum value from result and element at L


Assuming that mid is in right sorted subarray and we know we are in right sorted subarray
- All elements to the right of mid can be discarded 
    - Set new R = M - 1
- All elements to the left of mid will be in sorted order since element at L < element at R
- Find minimum value from result and element at L

- If minimum value not changed, entire set of elements can be discarded, since if element at L is greater than result,
all other elements after L in current sub array range will be greater than result as well.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int findMin(vector<int>& nums) {
    int mid, l = 0, r = nums.size()-1;
    int res = INT_MAX;

    while (l <= r) {

        if (nums[l] <= nums[r]) {
            res = min(res, nums[l]);
            break;
        }

        mid = (l+r)/2;
        res = min(res,nums[mid]);

        if (nums[l] <= nums[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }

    return res;
}


int main() {
    // vector<int> nums = {3,4,5,1,2};
    // vector<int> nums = {4,5,6,7,0,1,2};
    vector<int> nums = {11,13,15,17};

    int elem = findMin(nums);
    cout << elem << '\n';
    cout << '\n';
}