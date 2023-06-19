/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
https://www.youtube.com/watch?v=p-ss2JNynmw

Problem: https://leetcode.com/problems/find-all-anagrams-in-a-string/
Solution(s): 
- https://leetcode.com/problems/find-all-anagrams-in-a-string/solutions/1738073/short-and-simple-c-sliding-window-solution/

YouTube
NC - https://www.youtube.com/watch?v=G8xtZy0fDKg


A. Sliding Window (Optimal)

1. Two frequency vectors: 
    window - Dynamic; s-chars in current substring window
    countP - Fixed;   p-chars in t-string

2. Pre-checks:
    If pLen > sLen, return {}

3. First window substring = length of p-string
    Get count of first pLen chars and compare vectors.
    If equal, add 0 (as starting position) to result.

4. Two pointers start = 0 and end = pLen
5.  Increment count of char at end.
    Decrement count of char at start.

6. If the two freq vectors are equal, 
    append (start + 1) to result.
7. Increment start and end pointers;

8. Return result vector


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {

    int pLen = p.size();
    int sLen = s.size();

    if (pLen > sLen)
        return {};

    vector<int> countP(26,0);
    vector<int> window(26,0);
    
    for (int i = 0; i < pLen; i++) {
        countP[p[i]-'a']++;
        window[s[i]-'a']++;
    }
    
    vector<int> result;
    int start = 0, end = pLen;

    if (countP == window) 
        result.emplace_back(0);
    
    while (end < sLen) {
        window[s[end] - 'a']++;
        window[s[start] - 'a']--;
        
        if(countP == window) 
            result.push_back(start + 1);

        start++;
        end++;
    }
    return result;
}

/*
vector<int> findAnagrams(string s, string p) {

    if (p.size() > s.size())
        return {};
    
    if (s == p)
        return {0};

    map<char, int> countP;
    map<char, int> window;
    vector<int> result;

    for (auto ch : p)
        countP[ch] += 1;

    int start = 0, end = 0;
    int have = 0, need = countP.size();
    char chR = ' ', chL = ' ';

    while (end < s.length()) {

        chR = s.at(end);
        if (countP.find(chR) == countP.end()) {
            start = ++end;
            window.clear();
            have = 0;
            // cout << start << ' ' << end << '\n';
            continue;
        }

        window[chR] += 1;

        cout << "Before if" << endl;
        cout << start << ' ' << end << " : " << have << '\n';

        if ( (countP.find(chR) != countP.end()) && (window[chR] == countP[chR]) ) {
            cout << "if 1" << endl;
            have += 1;
        }
        if ( (countP.find(chR) != countP.end()) && (window[chR] > countP[chR]) ) {
            cout << "if 2" << endl;
            window[chR]--;
            start++;
        }

        cout << chR << " : " << window[chR] << '\n';

        cout << start << ' ' << end << " : " << have << '\n';
        cout << endl;

        while (have == need) {

            cout << "Have/Need 1" << endl;
            cout << start << ' ' << end << " : " << have << '\n';
            result.emplace_back(start);
            chL = s.at(start);
            

            cout << chL << " : ";
            cout << window[chL] << ' ';    
            window[chL] -= 1;
            cout << window[chL];
            cout << '\n';

            if ( (countP.find(chL) != countP.end()) && (window[chL] != countP[chL]) ) {
                cout << "Have/Need 2" << endl;
                cout << start << ' ' << end << " : " << have << '\n';
                have -= 1;
            }

            start++;
            cout << endl;
        }
        end++;
    }

    return result;
}
*/


int main() {

    string s = "cbaebabacd", p = "abc";
    // string s = "abab", p = "ab";
    // string s = "abaacbabc", p = "abc";

    vector<int> res = findAnagrams(s,p);

    cout << "Anagram indices: " ;
    for (const auto& elem : res)
        cout << elem << ' ';
    cout << '\n';

    return 0;
}