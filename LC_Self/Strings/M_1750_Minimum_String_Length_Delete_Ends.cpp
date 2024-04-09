/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends
Solution(s): 
    
YouTube
https://www.youtube.com/watch?v=XorbGp6gysg
*/


/*

A. Two-Pointer Solution

1. Start l,r at 0,n-1.
2. Iterate while l < r and characters match.
3. Again, iterate while l < r and characters match and keep incrementing l.
4. Again, iterate while l < r and characters match and keep decrementing r.
5. Return 0 if l > r, else return r-l+1.

Why does inner while loop have <= instead of < ?
Because we need to check if the next character is same as the current character.
If it is, we need to keep moving the pointer till we find a different character.
The <= is used to include the position where the character changes. 
When the character changes, the loop stops, but it includes the position where the character was the same before the change.
If you use < instead of <=, you would miss the position where the character changes, which would result in incorrect counting of the length of the substring.

Why using temp char?
Because we need to keep track of the character we are comparing with.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int minimumLength(string s) {
    int l = 0, r = s.size() - 1;
    int minLen = INT_MAX;
    char temp = ' ';

    while (l < r && s[l] == s[r]) {
        temp = s.at(l);
        while (l <= r && temp == s[l])
            l++;
        while (l <= r && temp == s[r])
            r--;
    }
    return l > r ? 0 : r - l + 1;
}


int main() {
    // string s = "ca";
    string s = "cabaabac";
    // string s = "aabccabba";
    // string s = "aabbaa";

    cout << minimumLength(s) << '\n';
    return 0;
}