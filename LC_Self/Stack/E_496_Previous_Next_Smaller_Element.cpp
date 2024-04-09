/*
Type: Monotonic Decreasing Stack ; Next Greater Element
Problem: https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
Solution(s): 
- https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
- https://medium.com/algorithms-digest/previous-smaller-element-e3996fb8be3c
- https://www.techiedelight.com/previous-smaller-element/

YouTube
NC - 
*/


/*

1. Brute Force - O(mn)
- For each element in nums1, find the next greater element in nums2
- If no greater element exists, return -1
- Maintain a hashmap for indices so we know whether the current element's next greater element needs to be found or not and then where to insert the answer.

2. Optimal solution - O(m + n)
- Use a stack to implement the monotonic decreasing stack
- We can be assured that the stack will be in decreasing order because every time we encounter a greater element, we pop the stack until we find a greater element or the stack is empty
- Maintain a hashmap for indices so we know whether the current element's next greater element needs to be found or not and then where to insert the answer.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<map>

using namespace std;

vector<int> nextSmallerElement(vector<int>& nums) {
    stack<pair<int, int>> temp;
    vector<int> answer(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++) {
        while (!temp.empty() && nums[i] < temp.top().second) {
            answer[temp.top().first] = nums[i];
            temp.pop();
        }
        temp.push({i, nums[i]});
    }    

    return answer;
}

vector<int> previousSmallerElement(vector<int>& nums) {
    stack<pair<int, int>> temp;
    vector<int> answer(nums.size(), -1);

    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!temp.empty() && nums[i] < temp.top().second) {
            answer[temp.top().first] = nums[i];
            temp.pop();
        }
        temp.push({i, nums[i]});
    }    

    return answer;
}

int main() {
    // vector<int> nums = {1,6,4,10,2,5};
    // vector<int> nums = {1,3,0,2,5};
    vector<int> nums = {2,1,5,6,2,3};

    vector<int> answerPrev = previousSmallerElement(nums);
    vector<int> answerNext = nextSmallerElement(nums);

    for (const auto& elem : answerPrev)
        cout << elem << "\t";
    cout << "\n";

    for (const auto& elem : answerNext)
        cout << elem << "\t";
    cout << "\n";

}