/*
Type: Searching Array, Binary Search
Problem: https://leetcode.com/problems/sqrtx/
Solution(s): 

*/


/*

A. Optimal Solution

1. Compare low LTE high and keep searching while this is true.
2. Compare target with middle value, 
3.  If greater, set low to one more than mid.
4.  If lesser, set high to one less than mid.
5.  Else, if equal, return mid.
6. Outside loop, return -1; to indicate the target was not found.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int mysqrt(int x) {
    int low = 1, high = x, mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (mid == x/mid)
            return mid;
        else if (mid < x/mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}


int main() {
    int target = 4;
    // int target = 8;
    
    int sqrt = mysqrt(target);
    cout << sqrt << '\n';
}