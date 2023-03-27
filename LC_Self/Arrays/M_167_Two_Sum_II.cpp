/*

Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=cQ1Oz4ckceM
*/


/*

A. Optimal Solution 

Eliminating elements from the right end
- Can "continue" loop once sum > target 
- As array is sorted, any number after 1st element which gives sum > target 
will increase sum and exceed target.
E.g. 1+10 > 9 -> skip 11 ;    3+7 > 9 -> skip 10,11;

1. Iterate through the list with L = 0 and R = n-1
2. If sum > target, R--
3. If sum < target, L++
4. Return indices

Note: 1-based indexing

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size()-1;
    vector<int> ts;
    int sum = 0;

    while (l < r) {
        sum = numbers[l] + numbers[r];
        if (sum > target)
            r--;
        else if (sum < target)
            l++;
        else {
            ts.emplace_back(l+1);
            ts.emplace_back(r+1);
            break;
        }
    }
    return ts;
}

int main() {

    vector<int> nums = {2,7,11,15};
    int target = 9;

    // vector<int> nums = {2,3,4};
    // int target = 6;

    // vector<int> nums = {-1,0};
    // int target = -1;

    vector<int> indices = twoSum(nums, target);

    for (const int &elem : indices)
        cout << elem << '\t';
    cout << '\n';

    return 0;
}