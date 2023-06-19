/*
Type: Monotonic Decreasing Stack ; Next Greater Element
Problem: https://leetcode.com/problems/number-of-visible-people-in-a-queue/
Solution(s): 

YouTube
https://www.youtube.com/watch?v=nzRG4dV4F_8
*/


/*

1. Brute Force
Right traversal -> TLE
Left traversal works slightly better but still gives TLE 
- We can break loop when first higher temp is reached and answer[i] != 0 anymore

2. Optimal solution
Start from end
- We know ahead of time all the warmer days
- Can create an algorithm with linear time complexity

We'll use a stack, why?
- LIFO principle
- At each iteration starting backwards, the last element placed on the stack represents the next day
- If this next day isn't a warmer day then we can keep popping the stack until we find a warmer day if it exists.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Iteration from the end
vector<int> canSeePersonsCount(vector<int>& heights) {
    
    stack<int> temp;
    vector<int> answer(heights.size(), 0);

    int visiblePeople = 0;

    for(int i = heights.size() - 1; i >= 0; i--) {
        int currHeight = heights[i];
        visiblePeople = 0;
            
        while (!temp.empty() && currHeight >= temp.top()) {
            visiblePeople += 1;
            temp.pop();
        }

        if (!temp.empty())
            visiblePeople += 1;
            
        answer[i] = visiblePeople;

        temp.push(currHeight);   
    }
    return answer;
}



int main() {
    vector<int> nums = {10,6,8,5,11,9};
    // vector<int> nums = {5,1,2,3,10};
    // vector<int> nums = {30,60,90};
    vector<int> answer = canSeePersonsCount(nums);

    for(auto it = answer.begin(); it != answer.end(); it++)
        cout << *it << " ";
    cout << "\n\n";

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