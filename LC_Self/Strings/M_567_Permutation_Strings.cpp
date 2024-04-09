/*
Problem: https://leetcode.com/problems/permutation-in-string/description/
Solution(s): 
- 

    
YouTube
NC - https://www.youtube.com/watch?v=UbyhOgBN834
- https://www.youtube.com/watch?v=XFh_AoEdOTw

*/


/*

A. Vector FreqMap with Sliding Window

1. Maintain a freqMap for each character in s1
2. For the same length as s1, maintain a freqMap for each character in s2
3. Set end pointer to s1.length()-1
4. Iterate through s2 and for each character:
    - Check whether freqMap1 == freqMap2
    - If true, return true
    - Else, increment end pointer by 1 and update freqMap2 with new character
    - Decrement start pointer by 1 and update freqMap2 with new character

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool checkInclusion(string s1, string s2) {
    int start = 0, end = 0;
    vector<int> freqMap1(26, 0);
    vector<int> freqMap2(26, 0);

    if (s1.length() > s2.length())
        return false;

    for (; end < s1.size(); end++) {
        freqMap1[s1[end] - 'a']++;
        freqMap2[s2[end] - 'a']++;
    }

    end = s1.length()-1;

    while (end < s2.length()) {
        if (freqMap1 == freqMap2)
            return true;
        end++;
        if (end < s2.length())
            freqMap2[s2[end] - 'a']++;
        freqMap2[s2[start] - 'a']--;
        start++;
    }
    return false;
}


int main() {
    string s1 = "ab", s2 = "eidbaooo";
    // string s1 = "ab", s2 = "eidboaoo";
    cout << checkInclusion(s1, s2) << '\n';
    return 0;
}