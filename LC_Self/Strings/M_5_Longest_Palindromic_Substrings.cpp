/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/longest-palindromic-substring/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=XYQecbcd6_c
*/


/*

A. Optimal Solution

1. Consider each character of the string as the middle element.
2. Expand outwards left and right one character at a time.
3. Check if these two new characters on either side are identical.
4. Compute and update max length string.
5. Break loop if either side's l/r goes out of bounds or characters are not equal.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string countPalindromes(string s, int l, int r) {
    string longPalinStr;
    int maxLen = 0, palinLen = 0;

    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        palinLen = r-l+1;
        if (palinLen > maxLen) {
            longPalinStr = s.substr(l,palinLen);
            maxLen = palinLen;
        }
        l--;
        r++;
    }

    return longPalinStr;
}

string longestPalindrome(string s) {
    int i;
    string answer, temp;

    for (i = 0; i < s.length(); i++) {
        temp = countPalindromes(s,i,i); // Odd length middle palin strings: l = i, r = i
        answer = temp.length() > answer.length() ? temp : answer;
        temp = countPalindromes(s,i,i+1); // Even length middle palin strings: l = i, r = i + 1
        answer = temp.length() > answer.length() ? temp : answer;
    }

    return answer;
}


int main() {
    // string s = "babad";
    string s = "cbbd";
    cout << longestPalindrome(s) << '\n';
    return 0;
}