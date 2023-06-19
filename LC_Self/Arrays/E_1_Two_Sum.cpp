/*

Problem: https://leetcode.com/problems/two-sum/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=KLlXCFG5TnA
*/


/*

A. Optimal Solution (HashMap, One Pass)

Used a list since it has same iterator find() like a hashmap.

- For ith element, all previous i-1 elements have been added to the map.
- When 1st element that makes up the target is encountered, 
    both its 2nd counterpart element as well as this 1st element itself are not yet in the map
- However, when we reach the 2nd element that makes up the target, 
    1st counterpart is already in the map, and condition is satisfied.

1. Iterate through the list.
2. Check If target - current element is in the list; 
    if yes, return indices of current element and (target - current element)
3. Add current element and its index in the map.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector <int> ts;
    vector <int>::iterator it;
    int diff = 0;

    for (int i = 0; i < nums.size(); i++) {
        diff = target - nums[i];
        it = find(nums.begin()+(i+1), nums.end(), diff);
        cout << i << "\n";
        if (it != nums.end()) {
            ts.push_back(i);
            ts.push_back(it - nums.begin());
            break;
        }
    }
    return ts;
}

int main() {

    // vector<int> nums = {2,7,11,15};
    // int target = 9;

    // vector<int> nums = {3,2,4};
    // int target = 6;

    vector<int> nums = {3,3};
    int target = 6;

    vector<int> indices2 = twoSum(nums, target);

    for (const int &elem : indices2)
        cout << elem << '\t';
    cout << '\n';

    return 0;
}