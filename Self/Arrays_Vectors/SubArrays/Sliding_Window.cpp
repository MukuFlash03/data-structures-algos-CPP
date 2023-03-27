/*
Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
*/


#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


vector<int> fixed_sw(vector<int> nums, int k) {

    vector<int> result;
    int currSum = 0;
    for (int i = 0; i < k; i++)
        currSum += nums[i];

    result.push_back(currSum);

    for (int i = 1; i < nums.size() - k + 1; i++) {
        currSum -= nums[i-1];
        currSum += nums[i+k-1] ;

        result.push_back(currSum);
    }

    return result;
}


int dynamic_sw(vector<int> nums, int x) {
    
    int minLen = INT_MAX;

    int currSum = 0;
    int start = 0, end = 0;

    while (end < nums.size()) {
        currSum += nums[end];
        end++;

        while (start < end && currSum >= x) {
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
    // vector<int> nums = {1,2,3,4,5,6};
    // vector<int> nums = {2,3,1,2,4,3};
    // vector<int> nums = {1,4,4};
    vector<int> nums = {1,1,1,1,1,1,1,1};

    /*
    vector<int> result = fixed_sw(nums, 7);

    cout << "3-length sum subarrays" << endl;
    for ( const int &elem : result )
        cout << elem << '\t';
    cout << '\n';
    */

    int minLen = dynamic_sw(nums,11);
    cout << "Min. length sum subarray = " << minLen << endl;
}