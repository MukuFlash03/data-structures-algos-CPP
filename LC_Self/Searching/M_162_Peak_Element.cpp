/*
Type: Binary Search
Problem: https://leetcode.com/problems/find-peak-element
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=kMzJy9es7Hc
*/


/*

A. Binary Search [O(logn) required]

Rules:
- Adjacent elements are not equal.

Modified binary search where we don't necessarily eliminate halves but find the peak element.

For monotonic increasing sequence, peak is the last element.
For monotonic decreasing sequence, peak is the first element.

If current value is not a peak element, then we are guaranteed that one of its neighbors is greater than it.
This is the direction we move towards - the direction of the greater neighbor.

 


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int mid, l = 0, r = nums.size()-1;
    while (l <= r) {
        mid = l + (r-l)/2;
        if (mid > 0 && nums[mid] < nums[mid - 1])
            r = mid - 1;
        else if (mid < nums.size() -1 && nums[mid] < nums[mid + 1])
            l = mid + 1;
        else
            return mid;
    }
}


int main() {
    vector<int> nums = {1,2,3,1};
    // vector<int> nums = {1,2,1,3,5,6,4};

    int elem = findPeakElement(nums);
    cout << elem << '\n';
    cout << '\n';
}