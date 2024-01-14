/*

https://www.byte-by-byte.com/coding-interview-101/

    &elem vs elem; auto vs auto&, const
        https://stackoverflow.com/questions/17032267/c11-range-based-for-loop-efficiency-const-auto-i-versus-auto-i
    
        - Copying (elem) more expensive than simply referencing (&elem)
        - Const ensures that elements not modified
    

Type: Precomputation (Pre-Postfix)

Problem: https://leetcode.com/problems/product-of-array-except-self/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=bNvIQI2wAjk


A. Sliding Window (Optimal)

1. First, calculate product going from L to R and update values for indices starting from 1 (0?) to n-1 in result[]
2. Next, calculate product going from R to L using updated result[] values from step 1 for indices 
3. Pre and Post initial values are 1. Previous First and Last element assumed to be 1 while calculating product

Note: Vector initialization
- Since vector is accessed by index, it is necessary to initialize it with size.
- If size is not known, use push_back() to add elements to vector.
- In this case, if we want to declare vector without size initialization, we can use push_back() to add elements to vector.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

void printResult(vector<int> &result) {
    cout << "Result:" << endl;
    for (const int &elem : result) 
        cout << elem << "\t";
    cout << endl;
}

vector<int> productExceptSelf(vector<int>& nums) {

    vector<int> result(nums.size(),1);
    int pre = 1, post = 1;

    for (int i = 0; i < nums.size(); i++) {
        result[i] = pre;
        pre *= nums[i];
    }

    printResult(result);
    
    for (int i = nums.size()-1; i >= 0; i--) {
        result[i] *= post;
        post *= nums[i];
    }

    printResult(result);

    return result;
}


int main() {

    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {-1,1,0,-3,3};
    
    vector<int> prodArr = productExceptSelf(nums);
    // printResult(prodArr);

    return 0;
}