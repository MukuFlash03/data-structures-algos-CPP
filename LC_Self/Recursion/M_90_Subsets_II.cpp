/*
Problem: https://leetcode.com/problems/subsets-ii/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=Vn2v6ajA7U0
*/


/*

Total no. of subsets = 2^n
n: Length of each subset (worst case)

Time complexity: O(n* 2^n)

Actual complexity would be lower since duplicates are being removed.


A. Optimal Solution

Tracking variable: index variable idx

In the decision tree, 
on the left subtree: whenver we choose to add an element, it will be included in all successors subsets
in the right subtree: should thus represent all subsets w/o elements already included when deciding whether to add an element or not,
                        since this element was already added on the left subtree

Thus whenever we face such situation, we will choose to skip such elements including duplicates and move to next new element.

We have to sort the input array and its time complexity O(nlogn) is insignificant compared to overall time complexity O(n*2^n).




1. If idx equals size of input array
    Append the current subset to the result array
    Return
2. For the left subtree
    - Append the current element to current subset
    - Recursive call with idx+1
3. For the right subtree
    - Pop the current element from current subset
        - This essentially removes the element just pushed in step 3 so as to maintain empty subset
    - Now this is the variation compared to M_78:
        - Skip the current element and all duplicates till the next element is not a duplicate
    - Recursive call with idx+1

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> subs;
vector<vector<int>> result;

void recurSubset(int idx, vector<int>& nums) {

    if (idx == nums.size()) {
        result.push_back(subs);
        return;
    }
    
    // All subsets that include nums[i]
    subs.push_back(nums[idx]);
    recurSubset(idx+1, nums);
    
    // All subsets that don't include nums[i]
    subs.pop_back();
    while (idx+1 < nums.size() && nums[idx] == nums[idx+1])
        idx += 1;
    recurSubset(idx+1, nums);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    recurSubset(0,nums);
    return result;
}

int main() {

    vector<int> nums = {1,2,2,3};
    // vector<int> nums = {0};

    vector<vector<int>> result = subsetsWithDup(nums);

    for (const auto &elem : result) {
        for (const auto &elem2 : elem) 
            cout << elem2 << ',';
        cout << '\t';
    }
    cout << '\n';

    return 0;
}