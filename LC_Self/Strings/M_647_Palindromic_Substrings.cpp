/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/palindromic-substrings/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=4RACzI5-du8
*/


/*

A. Optimal Solution

1. Consider each character of the string as the middle element.
2. Expand outwards left and right one character at a time.
3. Check if these two new characters on either side are identical.
4. Break loop if either side's l/r goes out of bounds or characters are not equal.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int countPalindromes(std::string s, int l, int r) {
    int count = 0;

    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        count++;
        l--;
        r++;
    }

    return count;
}

int countSubstrings(std::string s) {
    int i, count = 0;

    for (i = 0; i < s.length(); i++) {
        count += countPalindromes(s,i,i); // Odd length middle palin strings: l = i, r = i
        count += countPalindromes(s,i,i+1); // Even length middle palin strings: l = i, r = i + 1
    }

    return count;
}


int main() {
    // std::string s = "aaa";
    // std::string s = "aaab";
    std::string s = "abc";
    std::cout << countSubstrings(s) << '\n';
    return 0;
}