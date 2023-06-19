/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
https://www.youtube.com/watch?v=p-ss2JNynmw

Problem: https://leetcode.com/problems/longest-repeating-character-replacement/
Solution(s): 
- https://leetcode.com/problems/longest-repeating-character-replacement/solutions/1577162/easy-sliding-window-intution-explained-c-hashmap/
- https://leetcode.com/problems/longest-repeating-character-replacement/solutions/3066495/accepted-easy-solution-short-simple-best-method/


YouTube
NC - https://www.youtube.com/watch?v=gqXU1UyA8pk

Max value from map -> https://stackoverflow.com/questions/30611709/find-element-with-max-value-from-stdmap


A. Sliding Window

Points to Note:
- Can stick to finding length and not make actual character replacements
- Upper case characters only -> O(26.n) = O(n)
- Not necessary to make 'k' replacements (max. limit)
    - We want to replace the character that occurs least frequently in the current window
    - We want all characters in the current window to match the most frequent character in that window


Algorithm: 

- SW: L=0, R=0 
- Maintain a freqMap for each character in the current substring window
- Iterate through the length of the string and calculate the following for each current substring window:
    - Lsub = Length of current substring window
    - Cmax = Count of max freq character in the window
    - Crep = Lsub - Cmax
    
    - Now check whether Crep <= k
    - If true:
        - Compute and update the result = max(result, Lsub)
        - Move on to the next character (done by default on incrementing R at the end)
    - If false:
        - Decrement count of chL in freqMap
        - Increment L by 1 (L++) to slide window to the right

    - Using while loop gives incorrect answer for one case (long string testcase)
    - Works fine with if 


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;


int characterReplacement(string s, int k) {

    map<char,int> freqMap;
    int lSub = 0, cMax = 0;
    int maxLen = 0;
    int start = 0, end = 0;
    char chR = ' ', chL = ' ';

    if (s == "")
        return maxLen;

    while (end < s.length()) {

        chR = s.at(end);
        freqMap[chR]++;

        lSub = end-start+1;
        cMax = max(cMax, freqMap[chR]);
    
        // while (lSub - cMax > k && start < end) {
        if (lSub - cMax > k) {
            chL = s.at(start);
            freqMap[chL]--;
            start++;
        }
        maxLen = max(maxLen, end-start+1);
        
        cout << maxLen << ": " << start << ", " << end << '\n';
        cout << endl;

        end++;
    }
    return maxLen;
}

int main() {

    // string s = "ABAB";   int k = 2;
    // string s = "AACBABBA";   int k = 1;
    string s = "ABABBA";   int k = 2;
    // string s = "BAAA";   int k = 0;
    // string s = "EOEMQLLQTRQDDCOERARHGAAARRBKCCMFTDAQOLOKARBIJBISTGNKBQGKKTALSQNFSABASNOPBMMGDIOETPTDICRBOMBAAHINTFLH";   int k = 7;
    
    int maxLen = characterReplacement(s,k);
    cout << "Max length of substring = " << maxLen << endl;

    return 0;
}