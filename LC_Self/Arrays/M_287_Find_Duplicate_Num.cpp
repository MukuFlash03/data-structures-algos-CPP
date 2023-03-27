/*

Check Arrays for solution.
For LL, need to create appropriate LL with cycle.

Type: Linked List, Two Pointers, Floyd's Algo

Problem: https://leetcode.com/problems/find-the-duplicate-number/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=wjYnzkAhcNk
*/


/*

A. Optimal Solution

- Instead of thinking of input as values, consider them to be pointers
    - Each value points to their respective face value's index in the array
    - Note that, array is 0-indexed while input ranges from [1,n]

- Fast Pointer and Slow Pointer
    - Fast pointer completes at least one full loop of cycle starting from cycle start point.
    - It overtakes slow pointer once completely.
    - Then starting from 2nd cycle onwards, it may intersect with slow pointer or take more cycles.

- Three pointers used: 2 Slow, 1 Fast
    - 1 Slow and 1 Fast work as usual for Floyd's algo for detecting cycles.
    - 2nd Slow pointer will start when cycle is detected.
    - At this point, 1st Slow pointer will also continue from matching point.
    - Fast slow pointer remains as it is.
    - Now, when 1st and 2nd Slow pointer meet, our duplicate element is found.

- To summarize:
    - A = Intersection point of 1st Slow and Fast pointer.
    - B = Intersection point of 1st Slow and 2nd Slow pointer
        - This refers to start of cycle point.
    - Distance from A to B = Distance from origin to B.
    - B is answer to  be returned, i.e. duplicate element.


- Why are these two distances the same?
- Assume these values: 
    - p: Distance of 2nd slow pointer from Origin to Start of cycle (Point B)
    - c: Length of cycle
    - x: Distance of from point A to B

- Distance covered by Fast:
    = p   -> Origin to B
    = c   -> At least One complete round of cycle path
    = c-x -> Assuming A intersection occurs in 2nd cycle
    Total = p + c + (c-x)

- Distance covered by Slow:
    = p   -> Origin to B
    = c-x -> Assuming A intersection occurs in 2nd cycle
    Total = p + (c-x)

- Fast moves twice as fast as Slow: 
    = 2S = F
    = 2[p + c-x] = p + c + c-x
    = 2p + 2c - 2x = p + 2c - x
    = p = x
    Hence Proved.



B. HashSet Approach

- But cannot modify array -> no sorting allowed.
- Must use constant extra space


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums) {

    int slow = 0, fast = 0, slow2 = 0;

    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
            break;
    }

    while (true) {
        slow = nums[slow];
        slow2 = nums[slow2];
        if (slow == slow2)
            break;
    }

    return slow;
}


int main() {

    // vector<int> nums = {1,3,4,2,2};
    vector<int> nums = {3,1,3,4,2};

    int elem = findDuplicate(nums);
    cout << elem << '\n';

    return 0;
}