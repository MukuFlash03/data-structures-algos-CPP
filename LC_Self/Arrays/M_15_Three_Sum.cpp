/*

Problem: https://leetcode.com/problems/3sum/
Solution(s): https://leetcode.com/problems/3sum/solutions/1462423/c-both-two-pointers-and-hashmap-approach-explained/

YouTube
NC - https://www.youtube.com/watch?v=jzZsG8n2R9A
*/

// Emplace_back vs Push_back

/*

A. Optimal Solution 

- Sort the array -> helps handle duplicates: 
                        if same first element occurs again as neighboring element, can skip it
- For every element, treat the remaining subarray as a two sum II problem (L,R)
- Outer loop ending, else condition, can update either L/R pointer as two sum logic will handle the other pointer.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    if (nums.size() < 3)
        return {};

    if (nums[0] > 0)
        return {};

    vector<vector<int>> result;
    vector<int> triplets;
    int sum = 0, l, r;

    for (int i = 0; i < nums.size(); i++) {


        if ( (i > 0) && (nums[i] == nums[i-1]) )
            continue;
        
        l = i + 1;
        r = nums.size() - 1;

        while (l < r) {
            sum = nums[i] + nums[l] + nums[r];

            if (sum > 0)
                r--;
            else if (sum < 0)
                l++;
            else {
                result.push_back({nums[i], nums[l], nums[r]});
                l++;
                while ( (nums[l] == nums[l-1]) && (l < r) )
                    l++;
            }
        }
    }
    return result;
}

int main() {

    vector<int> nums = {-1,0,1,2,-1,-4};
    // vector<int> nums = {0,1,1};
    // vector<int> nums = {0,0,0};

    vector<vector<int>> triplets = threeSum(nums);

    for (const auto &elem : triplets) {
        for (const auto &num : elem)
            cout << num << "\t";
        cout << '\n';
    }

    return 0;
}