/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/valid-anagram/
Solution(s): 
    https://www.leetsolve.com/242-valid-anagram/
    https://www.geeksforgeeks.org/cpp-program-to-check-whether-two-strings-are-anagram-of-each-other/

YouTube
NC - https://www.youtube.com/watch?v=9UtInBqnCgA
*/


/*

A. Numeric Solution

1. Assign a prime number to each unique character.
2. Compute product of all these prime numbers.
3. Compare prime product of the two strings.

B. Frequency Mapping

0. If lengths not equal, return false.
1. Count character frequency for one string by incrementing count.
2. Count character frequency for second string by decrementing count.
3. If char count for any char is < 0 for second string, return false.
-- 4. Optionally, can check for char count == 0 in second string and erase that key from map.
-- 5. Optionally, can return freqMap.empty() evaluation.
4. Return true.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    map<char,int> freqMap;

    for (const auto &ch : s)
        freqMap[ch]++;

    for (const auto &ch : t) {
        freqMap[ch]--;
        if (freqMap[ch] < 0)
            return false;
        // if (freqMap[ch] == 0)
        //    freqMap.erase(ch);
    }

    // return freqMap.empty();
    return true;
}


int main() {
    // string s = "anagram", t = "nagaram";
    string s = "rat", t = "car";
    cout << isAnagram(s,t) << '\n';
    return 0;
}