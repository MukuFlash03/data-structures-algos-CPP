/*
Type: Monotonic Decreasing Queue ; Deque
Problem: https://leetcode.com/problems/sliding-window-maximum/
Solution(s): 

YouTube
Neetcode - https://www.youtube.com/watch?v=cTBiBSnjO3c
*/


/*

1. Brute Force

- Sort array.
- Sliding window
- Keep adding each new element
- Compute max for each window.

2. Optimal solution

- Sort array.
- Iterate through list.
    - If an element in the queue, goes out of the current window
        - Pop from the front end of queue.
    - If current element > back of queue
        - Pop from the back end of queue.
    - Add current element to the queue.
    - If current window size >= k
        - Add the max from current window to the result array.
        - Increment l
    - Increment r

Using a queue so that elements can be added/removed from the front as well as the back.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
    if (nums.size() == 1)
        return {nums[0]};

    vector<int> answer;
    deque<int> indices;

    int l = 0, r = 0;

    while (r < nums.size()) {
        while ( (!indices.empty()) && (nums[indices.back()] < nums[r]) )
            indices.pop_back();
        indices.push_back(r);

        if (l > indices.front())
            indices.pop_front();
        
        if (r + 1 >= k) {
            answer.push_back(nums[indices.front()]);
            l++;
        }
        r++;
    }
    return answer;
}



int main() {

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    
    // vector<int> nums = {1};
    // int k = 1;

    vector<int> answer = maxSlidingWindow(nums,k);

    for(auto it = answer.begin(); it != answer.end(); it++)
        std::cout << *it << " ";
    std::cout << '\n';

}