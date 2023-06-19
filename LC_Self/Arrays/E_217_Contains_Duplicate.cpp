/*
Problem: https://leetcode.com/problems/contains-duplicate/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=3OamzN90kPg
*/


/*

A. Optimal Solution (HashSet, One Pass)
Time: O(n)  Space: O(n)

1. Iterate through list.
2.  If ith element in HashSet
        Return true
3.  Add ith element to HashSet
4. Return false

B. Pre-Optimal Solution (One Pass)
Time: O(nlogn)  Space: O(1)

0. If list size = 0 or 1, Return false.
1. Sort the list.
2. Temp = 1st element
3. Iterate through the list from index 1
4.  If ith element equals temp
        Return true.
5.  Else
        temp = ith element
6. Return false

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>

using namespace std;


// Soln A
bool containsDuplicate1(vector<int>& nums) {

    if (nums.size() == 0)    return false;
    if (nums.size() == 1)    return false;

    set<int> solo;
    for (const auto &elem : nums) {
        if (solo.find(elem) != solo.end())
            return true;
        solo.emplace(elem);
    }
    return false;
}


// Soln B
bool containsDuplicate2(vector<int>& nums) {
        
    if (nums.size() == 0)    return false;
    if (nums.size() == 1)    return false;
    
    sort(nums.begin(), nums.end());
    int temp = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != temp)
            temp = nums[i];
        else    
            return true;
    }
    return false;
}

int main() {

    // vector<int> nums = {1,2,3,1};
    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {1,1,1,3,3,4,3,2,4,2};

    bool flag1 = containsDuplicate1(nums);
    bool flag2 = containsDuplicate2(nums);
    cout << flag1 << '\t' << flag2 << endl;

    return 0;
}