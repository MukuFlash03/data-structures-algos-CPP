/*

Type: 

Problem: https://leetcode.com/problems/number-of-1-bits/
Solution(s): 
- https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

YouTube
NC - https://www.youtube.com/watch?v=5Km3utixwZs
*/


/*

A. Bitwise AND

- Rightmost bit of a number is unset by using the expression: num & (num - 1)
- Keep unsetting the rightmost bit until the number becomes 0.
- The number of times the loop runs is the number of set bits in the number.

*/



#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int hammingWeight(uint32_t n) {

    int count = 0;

    while (n) {
        n &= (n - 1);
        count++;
    }

    return count;
}

int hammingWeightRecursive(uint32_t n) {

    if (n == 0) {
        return 0;
    }

    return 1 + hammingWeightRecursive(n & (n - 1));
}

int main() {

    uint32_t num = 00000000000000000000000000001011;
    // uint32_t num = 00000000000000000000000010000000
    // uint32_t num = 11111111111111111111111111111101


    cout << hammingWeight(num) << '\n';
    cout << hammingWeightRecursive(num) << '\n';


    return 0;
}