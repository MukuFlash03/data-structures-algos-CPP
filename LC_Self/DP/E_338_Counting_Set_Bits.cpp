/*

Type: 

Problem: https://leetcode.com/problems/counting-bits/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=RyBM56RIWrM
*/


/*

A. Bitwise AND

- Rightmost bit of a number is unset by using the expression: num & (num - 1)
- Keep unsetting the rightmost bit until the number becomes 0.
- The number of times the loop runs is the number of set bits in the number.

B. DP

- Store offset value which equals most recent power of 2 encountered.
- If offset * 2 == i, then offset = i.
- For every number, add 1 to the number of set bits to the number at position i - offset in the dp array.

*/



#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int hammingWeightRecursive(uint32_t n) {
    if (n == 0)
        return 0;

    return 1 + hammingWeightRecursive(n & (n - 1));
}

vector<int> countBits(int n) {
    vector<int> setBits(n+1, 0);

    for (uint32_t i = 1; i <= n; i++)
        setBits[i] = hammingWeightRecursive(i);

    return setBits;
}

vector<int> countBitsDP(int n) {

    vector<int> setBits(n+1, 0);
    int offset = 1;

    for (int i = 1; i <= n; i++) {
        if (offset * 2 == i) {
            offset = i;
        }

        setBits[i] = 1 + setBits[i - offset];
    }

    return setBits;
}

int main() {

    // int n = 2;
    int n = 5;

    vector<int> setBits = countBits(n);
    
    for (const auto& elem : setBits)
        cout << elem << "\t";
    cout << '\n';

    return 0;
}