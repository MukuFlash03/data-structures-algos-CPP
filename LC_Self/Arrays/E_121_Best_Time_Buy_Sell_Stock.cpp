/*

Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=1pkOgXD63yU
*/


/*

A. Optimal Solution (One-pass using Two-pointers)

1. Left pointer starts at left-end (i=0) and represents Buy price.
   Right pointer starts at left-end (i=1) and represents Sell price.
   
2. Update L to R value if R < L
This is done since we want to buy low and sell high; hence L (buy) will be updated to lower buy price.
Also, increment R value to one element ahead of latest updated L position.

3. Else when R > L, then compute max profit and update it.
*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {

    int l = 0, r = 1;
    int profit = 0;

    while (l <= r && r < prices.size()) {
        if (prices[l] > prices[r])
            l = r;
        else 
            profit = max(profit, prices[r] - prices[l]);
        r++;
    }
    return profit;
}

int main() {
    std::vector<int> nums = {7,1,5,3,6,4};
    // std::vector<int> nums = {7,6,4,3,1};
    // std::vector<int> nums = {1,2,3,4,5};
    

    int profit = maxProfit(nums);
    std::cout << profit << '\n';

    return 0;
}