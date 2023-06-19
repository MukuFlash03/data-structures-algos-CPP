/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
https://www.youtube.com/watch?v=p-ss2JNynmw

Problem: https://leetcode.com/problems/minimum-window-substring/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=jSto0O4AJbM


A. Sliding Window (Optimal)

1. Two frequency maps: 
    window - Dynamic; s-chars in current substring window
    countT - Fixed;   t-chars in t-string

2. Two counters: 
    need = Fixed; unique chars in countT
    have = Dynamic; unique chars in window

3. Outer loop: Start expanding end pointer and updating window map
4.  If char at end pointer exists in countT and freq is same in both maps,
      then increment "have" by 1
5.  While have == need, 
      update min length of substring with latest start and end pointers
      update resLR with latest start and end pointers
6.    Contract window by one character by incrementing start pointer and updating window map
7.    If char at start pointer exists in countT and freq is less in window map
       then decrement "have" by 1
8.    Increment start;
9.  Increment end.

10. Update start and end pointers with latest resLR values
11. Return substring with start and end from resLR as bounds if min length != INT_MAX
        else return ""


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;


string minWindow(string s, string t) {

    if (t == "")
        return "";
    
    if (s == t)
        return s;

    map<char, int> countT;
    map<char, int> window;
    pair<int, int> resLR = make_pair(-1,-1);

    for (auto ch : t)
        countT[ch] += 1;

    int minLen = INT_MAX;
    int start = 0, end = 0;
    int have = 0, need = countT.size();

    cout << "Size: " << need << endl;

    char chR = ' ', chL = ' ';

    /*
    for (auto it = countT.begin(); it != countT.end(); it++)
        cout << it->first << ": " << it->second << endl;
    cout << endl;
    */

    while (end < s.length()) {
        chR = s.at(end);
        window[chR] += 1;

        if ( (countT.find(chR) != countT.end()) && (window[chR] == countT[chR]) )
            have += 1;

        while (have == need) {
            if (end-start + 1 < minLen) {
                resLR.first = start;
                resLR.second = end;
                minLen = end-start + 1;
            }

            chL = s.at(start);
            window[chL] -= 1;

            if ( (countT.find(chL) != countT.end()) && (window[chL] < countT[chL]) )
                have -= 1;

            start++;
        }
        end++;
    }

    start = resLR.first;
    end = resLR.second;

    return (minLen != INT_MAX) ? s.substr(start, end-start + 1) : "";  
}


int main() {

    // string s = "ADOBECODEBANC", t = "ABC";
    // string s = "a", t = "a";
    // string s = "a", t = "aa";
    // string s = "aa", t = "aa";
    string s = "bbaa", t = "aba";

    string res = minWindow(s,t);

    cout << "Min. window substring = " << res << endl;

    return 0;
}