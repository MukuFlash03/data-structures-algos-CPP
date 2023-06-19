/*
Type: HashMap

Problem: https://leetcode.com/problems/ransom-note/
Solution(s): 
- https://leetcode.com/problems/ransom-note/solutions/2910682/c-easy-solution/
*/


/*

A. Frequency Mapping

// Similar to 242_Valid_Anagram

1. Count character frequency for one string by incrementing count.
2. If character in ransom string doesn't exist in freqMap, return false.
3. Count character frequency for second string by decrementing count.
4. If char count for any char is < 0 for second string, return false.
5. Return true.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {

    map<char,int> freqMap;

    for (const auto &ch : magazine)
        freqMap[ch]++;

    for (const auto &ch : ransomNote) {
        
        if (freqMap.find(ch) == freqMap.end())
            return false;
        
        freqMap[ch]--;

        if (freqMap[ch] < 0)
            return false;
    }

    return true;
}


int main() {
    // string ransomNote = "a", magazine = "b";
    // string ransomNote = "aa", magazine = "ab";
    string ransomNote = "aa", magazine = "aab";
    cout << canConstruct(ransomNote,magazine) << '\n';
    return 0;
}