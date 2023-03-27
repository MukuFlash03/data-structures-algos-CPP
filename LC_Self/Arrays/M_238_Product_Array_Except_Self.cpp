/*

https://www.byte-by-byte.com/coding-interview-101/

    &elem vs elem; auto vs auto&, const
        https://stackoverflow.com/questions/17032267/c11-range-based-for-loop-efficiency-const-auto-i-versus-auto-i
    
        - Copying (elem) more expensive than simply referencing (&elem)
        - Const ensures that elements not modified
    

Type: Precomputation (Pre-Postfix)

Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=jSto0O4AJbM


A. Sliding Window (Optimal)

1. First, calculate product going from L to R and update values for indices starting from 1 to n-1 in result[]
2. Next, calculate product going from R to L using updated result[] values from step 1 for indices 
3. Pre and Post initial values are 1. Previous First and Last element assumed to be 1 while calculating product

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {

    vector<int> result(nums.size(),1);
    int pre = 1, post = 1;

    for (int i = 0; i < nums.size(); i++) {
        result[i] = pre;
        pre *= nums[i];
    }
    
    for (int i = nums.size()-1; i >= 0; i--) {
        result[i] *= post;
        post *= nums[i];
    }

    return result;
}


int main() {

    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {-1,1,0,-3,3};
    
    vector<int> prodArr = productExceptSelf(nums);

    cout << "Product Array:" << endl;
    for (const int &elem : prodArr) 
        cout << elem << "\t";
    cout << endl;

    return 0;
}