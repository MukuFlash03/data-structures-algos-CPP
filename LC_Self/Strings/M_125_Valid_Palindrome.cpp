/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/valid-palindrome/
Solution(s): 
    
YouTube
NC - https://www.youtube.com/watch?v=jJXJ16kPFWg
*/


/*

A. Two-Pointer Solution

1. Start l,r at 0,n-1.
2. While char is not alphanumeric: l++, r--
3. Check if lowercase char matches for l,r; return false if no match.
4. Update l,r = l++, r--
5. Return true.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool isAlphaNumeric(char ch) {
    return (
        (ch >= '0' && ch <= '9') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z')
    );
}

bool isPalindrome(string s) {
    
    int l = 0, r = s.length()-1;
    
    while (l < r) {
        while ( (l < r) && (!isAlphaNumeric(s.at(l))) )
            l++;
        while ( (l < r) && (!isAlphaNumeric(s.at(r))) )
            r--;

        if (tolower(s.at(l)) != tolower(s.at(r)))
            return false;

        l++;
        r--;
    }
    
    return true;
}


int main() {
    string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    // string s = " ";
    cout << isPalindrome(s) << '\n';
    return 0;
}