/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
https://www.youtube.com/watch?v=p-ss2JNynmw

Problem: https://leetcode.com/problems/subarray-sum-equals-k
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=fFVZt-6sgyo


A. Prefix Sum (Optimal) 

O(n) time, O(n) space

1. Iterate only once from start to end.
2. Calculate sum of all elements upto current pointer.
3. Calculate the difference between current sum and target.
4. If the difference is present in the map, then increment count by the value of the difference in the map.
5. Increment the count of the current sum in the map.
6. Return count.


B. Sliding Window (Many failed testcases)

1. Doesn't work due to present of negative elements.
2. Similar approach to S_3_1_Longest_Subarr_Sum_K.cpp
3. Increment count when k equals target.



*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int currSum = 0;
    int diff = 0;
    map<int, int> prefixSum;

    prefixSum[0] = 1;

    for (const auto& elem : nums) {
        currSum += elem;
        diff = currSum - k;

        if (prefixSum.find(diff) != prefixSum.end()) {
            count += prefixSum[diff];
        }

        prefixSum[currSum]++;
    }

    return count;
}


int main() {
    vector<int> nums = {1,1,1};
    int k = 2;

    // vector<int> nums = {1,2,3};
    // int k = 3;

    int count = subarraySum(7, nums);
    cout << "Total number of subarrays = " << count << endl;

    return 0;
}