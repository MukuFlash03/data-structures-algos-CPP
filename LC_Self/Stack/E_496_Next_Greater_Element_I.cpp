/*
Type: Monotonic Decreasing Stack ; Next Greater Element
Problem: https://leetcode.com/problems/next-greater-element-i
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=68a1Dc_qVq4
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

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> indices;
    stack<int> temp;
    vector<int> answer(nums1.size(), -1);

    for (int i = 0; i < nums1.size(); i++) 
        indices[nums1[i]] = i;

    for (int i = 0; i < nums2.size(); i++) {
        while (!temp.empty() && nums2[i] > temp.top()) {
            answer[indices[temp.top()]] = nums2[i];
            temp.pop();
        }

        if (indices.find(nums2[i]) != indices.end())
            temp.push(nums2[i]);
    }    

    return answer;
}

int main() {
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    // vector<int> nums1 = {2,4}, nums2 = {1,2,3,4};

    vector<int> answer = nextGreaterElement(nums1, nums2);

    for (const auto& elem : answer)
        cout << elem << "\t";
    cout << "\n";

}