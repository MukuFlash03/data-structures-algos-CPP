/*
Problem: https://leetcode.com/problems/permutations/
Solution(s): https://www.codingbroz.com/permutations-leetcode-solution/

YouTube
NC - https://www.youtube.com/watch?v=s7AvT7cGdSo
*/


/*

Rough time complexity: O(n^k)
n: Length of decision tree
k: Height of decision tree

Better estimate: O(k*nCk)

A. Optimal Solution

Decision tree:
- Going deeper, exclude first element in current larger subset
- Going upwards, append this excluded element to the subsets returned from successor levels
- This would be new subset list at this point to be returned upwards
- Base case includes single value in subset; at this point return upwards



*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> result;

void recurPermute(int idx, vector<int>& nums) {

    if (idx == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[i], nums[idx]);
        recurPermute(idx+1, nums);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    recurPermute(0,nums);
    return result;
}


int main() {

    vector<int> nums = {1,2,3};
    // vector<int> nums = {0,1};
    // vector<int> nums = {1};

    vector<vector<int>> result = permute(nums);

    for (const auto &elem : result) {
        for (const auto &elem2 : elem) 
            cout << elem2 << ',';
        cout << '\t';
    }
    cout << '\n';


    return 0;
}