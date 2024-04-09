/*


Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=U8XENwh8Oy8


A. Binary Search [O(logn) required]

The array is divided into two sorted lists.
Binary search has three pointers: L,M,R; with L <= R always satisfied.

How to check which portion of array we are in?
- If L <= M, then we are in left subarray and then M is part of Left subarray

Assuming that mid is in left sorted subarray and we know we are in left sorted subarray
- Say target > mid, 
    then all elements to the left of mid can be discarded
- Say target < mid, 
    if target < first element in the left sorted subarray
        then all elements to the left of mid can be discarded
    if target > first element in left sorted subarray
        then all elements to the right of mid can be discarded

Assuming that mid is in right sorted subarray and we know we are in right sorted subarray
- Say target < mid, 
    then all elements to the right of mid can be discarded
- Say target > mid, 
    if target > last element in the right sorted subarray
        then all elements to the right of mid can be discarded
    if target < last element in right sorted subarray
        then all elements to the left of mid can be discarded

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


int search(vector<int>& nums, int target) {

    int mid, l = 0, r = nums.size() - 1;

    while (l <= r) {

        mid = (l+r)/2;
        if (target == nums[mid])
            return mid;
        
        // Checking whether middle values is in left subarray 
        if (nums[l] <= nums[mid]) {
            if ( (target > nums[mid]) || (target < nums[l]) )
                l = mid + 1;
            else
                r = mid - 1;   
        }

        // Else, middle value is in right subarray
        else {
            if ( (target < nums[mid]) || (target > nums[r]))
                r = mid - 1;
            else
                l = mid + 1;
        }
    }

    return -1;
}


int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    // int target = 3;

    // vector<int> nums = {1};
    // int target = 0;

    vector<int> nums = {3, 5, 1};
    int target = 3;

    int index = search(nums, target);
    cout << index << endl;

    return 0;
}