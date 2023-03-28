/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
https://www.youtube.com/watch?v=p-ss2JNynmw

Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=wiGpQwVHdE0


A. Sliding Window (Optimal)

1. Set used to maintain list of unique chars encountered.
2. Outer loop: Fetch char at end pointer
3.  Inner loop: While chR exists in set, 
        Keep erasing chars from left end (chL) using start pointer
        Increment start pointer by 1
4.  Add chR to set and increment end pointer by 1
5.  Update maxLen with greater window size or current value
6. Return max window size

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int lengthOfLongestSubstring(string s) {

    set<char> currWindow;
    int start = 0, end = 0;
    int maxLen = 0;
    char chL = ' ', chR = ' ';

    if (s == "")
        return maxLen;

    while (end < s.length()) {
        chR = s.at(end);

        while (currWindow.find(chR) != currWindow.end()) {
            chL = s.at(start);
            currWindow.erase(chL);
            start++;
        }

        currWindow.emplace(chR);
        maxLen = max(maxLen, end-start+1);

        end++;
    }

    return maxLen;
}


int main() {

    string s = "abcabcbb";
    // string s = "bbbbb";
    // string s = "pwwkew";

    int maxLen = lengthOfLongestSubstring(s);

    cout << "Max length of substring = " << maxLen << endl;

    return 0;
}