/*

Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=1pkOgXD63yU
*/


/*

A. Optimal Solution

1. Iterate through the list from 1 to len-1
2. If current value is greater than previous value,
3.   Add difference between these values to the profit.
4. Return profit.

In each case we are only considering increases from previous buy price.
We are looking for inclines or rises and not declines or falls.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
        if (prices[i] > prices[i-1])
            profit += prices[i] - prices[i-1];
    return profit;
}

int main() {
    vector<int> nums = {7,1,5,3,6,4};
    // vector<int> nums = {7,6,4,3,1};
    // vector<int> nums = {1,2,3,4,5};
    

    int profit = maxProfit(nums);
    cout << profit << '\n';

    return 0;
}