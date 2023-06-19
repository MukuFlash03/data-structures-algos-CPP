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

int main() {

    // int n = 2;
    // int n = 3;
    int n = 5;

    cout << climbStairs(n) << "\n";

    return 0;
}