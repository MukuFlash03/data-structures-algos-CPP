/*
Type: Searching Array
Problem: https://leetcode.com/problems/binary-search/
Solution(s): 

*/


/*

A. Optimal Solution

1. Compare low LTE high and keep searching while this is true.
2. Compare target with middle value, 
3.  If greater, set low to one more than mid.
4.  If lesser, set high to one less than mid.
5.  Else, if equal, return mid.
6. Outside loop, return -1; to indicate the target was not found.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target) {

    if (nums.size() == 1 && nums[0] == target)
        return 0;
    if (nums.size() == 1 && nums[0] != target)
        return -1;

    int low = 0, high = nums.size()-1, mid;

    while (low <= high) {
        mid = (low + high)/2;

        if (target > nums[mid])
            low = mid + 1;
        else if (target < nums[mid])
            high = mid - 1;
        else if (target == nums[mid])
            return mid;
    }
    return -1;
}


int main() {
    // vector<int> nums = {-1,0,3,5,9,12};
    // int target = 9;
    // int target = 2;


    vector<int> nums = {2,5};
    int target = 5;
    
    int index = search(nums, target);
    cout << index << '\n';
    cout << '\n';

    // for(auto it = answer.begin(); it != answer.end(); it++)
    // for ( const vector<int> &elem : answer)
        // cout << elem[0] << ", " << elem[1] << "\n";
    // cout << "\n\n";

    /*
    vector<pair<int, int>> test = {make_pair(1,1), make_pair(2,2)};
    // vector<pair<int, int>>::iterator it;
    for (auto it = test.begin(); it != test.end(); it++)
            cout << it->first << ", " << it->second << '\t';
    cout << '\n';

    for ( const pair<int,int> &elem : test )
        cout << elem.first << ", " << elem.second << '\t';
    cout << '\n';
    */

}