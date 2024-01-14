/*

Type: Memoization, Bottom-up

Problem: https://leetcode.com/problems/climbing-stairs/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=Y0lT9Fck7qI
*/


/*

A. Basic DP Approach




*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

// M1
int climbStairs(int n) {
    int one = 1, two = 1;
    int temp = 0;

    for (int i = 0; i < n-1; i++) {
        temp = one;
        one += two;
        two = temp;
    }

    return one;
}

// M2
int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {

    // int n = 2;
    // int n = 3;
    int n = 5;

    cout << climbStairs(n) << "\n";

    return 0;
}