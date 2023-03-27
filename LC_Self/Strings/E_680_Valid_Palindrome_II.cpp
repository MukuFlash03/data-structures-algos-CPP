/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/valid-palindrome-ii/
Solution(s): 
    
YouTube
NC - https://www.youtube.com/watch?v=JrxRYBwG6EI
*/


/*

A. Two-Pointer Solution

1. Start l,r at 0,n-1.
2. Iterate while l < r
3. Check if l and r characters match.
4.  If not, remove l and r chars from current substring one at a time
        - Take care of proper indices:
        - L char removal: substr(l+1,r-(l+1)+1)
        - R char removal: substr(l,(r-1)-l+1)
5.  Return true/false whether these two substrings are palindrome or not
6. Update l,r = l++, r--
5. Return true, since at this stage, palindrome guaranteed.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    
    int l = 0, r = s.length()-1;

    while (l < r) {
        if (tolower(s.at(l)) != tolower(s.at(r)))
            return false;
        l++;
        r--;
    }
    return true;
}

bool validPalindrome(string s) {
    
    int l = 0, r = s.length()-1;

    while (l < r) {
        if (s.at(l) != s.at(r)) {
            return isPalindrome(s.substr(l+1,r-(l+1)+1))
                || isPalindrome(s.substr(l,(r-1)-l+1));
        }
        l++;
        r--;
    }
    return true;
}


int main() {
    string s = "aba";
    // string s = "abca";
    // string s = "abc";
    cout << validPalindrome(s) << '\n';
    return 0;
}