/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/palindromic-substrings/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=P1Ic85RarKY
*/


/*

A. Optimal Solution

1. Three pointers: 
    last = end of nums1
    m = end of data in nums1
    n = end of data in nums2
2. Compare last data values of nums1 and nums2 and put larger value in last
3. Decrement index corresponding to larger value
4. Decrement last
5. Put all remaining data values of nums2 into nums1 from current last till start of nums1

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int last = m + n - 1;

    while (m > 0 && n > 0) {
        if (nums1[m-1] > nums2[n-1]) {
            nums1[last] = nums1[m-1];
            m--;
        }
        else {
            nums1[last] = nums2[n-1];
            n--;
        }
        last--;
    }

    while (n > 0) {
        nums1[last] = nums2[n-1];
        n--;
        last--;
    }
}


int main() {

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for (const int &elem : nums1)
        cout << elem << '\t';
    cout << '\n';

    return 0;
}