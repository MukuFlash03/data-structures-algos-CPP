/*
Type: Monotonic Decreasing Stack ; Next Greater Element
Problem: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
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

vector<int> finalPrices(vector<int>& prices) {
    vector<int> discounts(prices.size(), 0);
    vector<int> finalDiscountedPrices(prices.size(), 0);
    stack<pair<int, int>> temp;
    
    for (int i = 0; i < prices.size(); i++) {
        while (!temp.empty() && prices[i] <= temp.top().second) {
            discounts[temp.top().first] = prices[i];
            temp.pop();
        }
        temp.push({i, prices[i]});
    }

    for (int i = 0; i < prices.size(); i++) {
        finalDiscountedPrices[i] = prices[i] - discounts[i];
    }
    return finalDiscountedPrices;
}

int main() {
    vector<int> nums = {8,4,6,2,3};
    // vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {10,1,1,6};

    vector<int> answer = finalPrices(nums);

    for (const auto& elem : answer)
        cout << elem << "\t";
    cout << "\n";

}