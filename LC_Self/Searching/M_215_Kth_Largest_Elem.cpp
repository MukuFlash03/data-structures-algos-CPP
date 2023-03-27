/*
Type: Searching Array
Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=XEmy13g1Qxc
*/


/*

A. Optimal Solution: Quick Select -> similar to Quick Sort

1. First perform quick sort:
    Choose a random element as pivot value.
    Iterate from l to r
        Elements lesser than pivot as brought to LHS by incrementing pivot pointer.
        Elements greater than pivot brought to RHS, but pivot pointer is not modified.
    Finally, chosen pivot element is swapped with the latest location of the pivot pointer.
    Thus, pivot pointer separates array into two halves:
        LHS: lesser than pivot
        RHS: greater than pivot
    Note: Elements in both halves may not be in sorted order.

2. Next, need to find kth largest element.
    This will be in one of the two halves.
    Will recursively run same algo as step 1 to find it.
    If target exactly equal to value at current pivot pointer, then we have found our value.

    Target index = len - k

B. Heap Approach

Complexity: O(n + klogn)
Each pop operation takes logn time.

1. Max heapify.
2. Pop k times to get kth largest element.

C. Naive Approach

1. Sort array.
2. Get nums[len - k] th element.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int quickSelect(int l, int r, vector<int>& nums, int k) {
    int pivot = nums[r];
    int p = l;
    int temp = 0;

    for (int i = l; i < r; i++) {
        if (nums[i] <= pivot) {
            temp = nums[p];
            nums[p] = nums[i];
            nums[i] = temp;
            p++;
        }
    }

    temp = nums[p];
    nums[p] = nums[r];
    nums[r] = temp;

    if (k > p)
        return quickSelect(p + 1, r, nums, k);
    else if (k < p)
        return quickSelect(l, p - 1, nums, k);
    else 
        return nums[p];
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    k = n - k;
    return quickSelect(0, n-1, nums, k);
}


int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    // vector<int> nums = {3,2,3,1,2,4,5,5,6};
    // int k = 4;

    int index = findKthLargest(nums, k);
    cout << index << '\n';
    cout << '\n';
}