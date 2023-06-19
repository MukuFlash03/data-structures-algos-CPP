/*
Problem: https://leetcode.com/problems/subsets/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=REOH22Xwdkk
*/


/*

Total no. of subsets = 2^n
n: Length of each subset (worst case)

Time complexity: O(n* 2^n)


A. Optimal Solution

Tracking variable: index variable idx

1. If idx equals size of input array
    Append the current subset to the result array
    Return
2. For the left subtree
    - Append the current element to current subset
    - Recursive call with idx+1
3. For the right subtree
    - Pop the current element from current subset
        - This essentially removes the element just pushed in step 3 so as to maintain empty subset
    - Recursive call with idx+1

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int> subs;
vector<vector<int>> result;

void recurSubset(int idx, vector<int>& nums) {

    if (idx == nums.size()) {
        result.push_back(subs);
        // cout << idx << ": " << subs.back() << '\n';
        return;
    }
    
    subs.push_back(nums[idx]);
    recurSubset(idx+1, nums);
    
    subs.pop_back();
    recurSubset(idx+1, nums);
}

vector<vector<int>> subsets(vector<int>& nums) {
    recurSubset(0,nums);
    return result;
}

int main() {

    vector<int> nums = {1,2,3};
    // vector<int> nums = {0};

    vector<vector<int>> result = subsets(nums);

    for (const auto &elem : result) {
        for (const auto &elem2 : elem) 
            cout << elem2 << ',';
        cout << '\t';
    }
    cout << '\n';

    return 0;
}