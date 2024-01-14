/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/intersection-of-two-arrays
Solution(s): 

YouTube
NC - 
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
#include<vector>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    int i = 0, j = 0, prev = -1;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            if(prev != nums1[i]){   
                result.push_back(nums1[i]);
                prev = nums1[i];
            }
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            j++;
        }
    }

    return result;
}


int main() {

    // vector<int> nums1 = {1,2,2,1};
    // vector<int> nums2 = {2,2};

    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    vector<int> result = intersection(nums1, nums2);

    for (const int &elem : result)
        cout << elem << '\t';
    cout << '\n';

    return 0;
}