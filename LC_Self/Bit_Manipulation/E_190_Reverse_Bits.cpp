/*

Type: 

Problem: https://leetcode.com/problems/reverse-bits/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=UcoN6UjAI64
*/


/*

A. Bitwise Operations

- Initialize a reversed number to 0.
- Right shift the number by i and AND it with 1 to get the ith bit.
- Left shift the ith bit by 31 - i and OR it with the reversed number.
- Return reversed number.


*/



#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

uint32_t reverseBits(uint32_t n) {

    uint32_t reversed = 0;
    uint32_t bitSet = 0;

    for (int i = 0; i < 32; i++) {
        bitSet = (n >> i) & 1;
        reversed |= (bitSet << (31 - i));
    }

    return reversed;
}

int main() {

    uint32_t num = 0b00000010100101000001111010011100;
    // uint32_t num = 0b11111111111111111111111111111101
    // uint32_t num = 0b11111111111111111111111111111101


    cout << reverseBits(num) << '\n';


    return 0;
}