/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
https://www.youtube.com/watch?v=p-ss2JNynmw

Problem: https://leetcode.com/problems/longest-repeating-character-replacement/
Solution(s): 
- https://leetcode.com/problems/longest-repeating-character-replacement/solutions/1577162/easy-sliding-window-intution-explained-c-hashmap/
- https://leetcode.com/problems/longest-repeating-character-replacement/solutions/3066495/accepted-easy-solution-short-simple-best-method/
- https://leetcode.com/problems/longest-repeating-character-replacement/description/comments/1568732


YouTube
NC - https://www.youtube.com/watch?v=gqXU1UyA8pk

Max value from map -> https://stackoverflow.com/questions/30611709/find-element-with-max-value-from-stdmap


A. Sliding Window

Points to Note:
- Can stick to finding length and not make actual character replacements
- Upper case characters only -> O(26.n) = O(n)
- Not necessary to make 'k' replacements (max. limit)
    - We want to replace the character that occurs least frequently in the current window as the no. of replacements (k) is limited
    - We want all characters in the current window to match the most frequent character in that window
    - E.g. ABABB, k=2
        - We want to replace 'A' with 'B' to get 'BBBBB' (5 B's) since B occurs most frequently and we have 2 replacements
        - We don't want to replace 'B' with 'A' to get 'AAAAA' (5 A's) since A occurs less frequently and we would make 3 replacements
    - lSub - cMax represent no. of replacements needed as we want to replace all characters except the most frequent one.

 O(n) approach
 - This avoids traversing the freqMap each time to find the max value, thus avoiding O(26) of O(26.n)
- Instead, we maintain a variable to store the max value and update it as and when we encounter a new max value
- This is done by comparing the current max value with the count of the character being inserted into the map
- If the count of the character being inserted is greater than the current max value, then update the max value
    - This ensures the condition is still met: lSub - cMax <= k
    - Since the max value is updated, the condition is still met even if the count of the character being inserted is greater than the current max value
- Else, do not update the max value
    - This is because, if the value of max frequency is reduced, then the condition may not be met as it LHS may become greater than RHS
     -Hence, the final result length would not be affected anyways


Algorithm: 

- Sliding Window: L=0, R=0 
- Maintain a freqMap for each character in the current substring window
- Iterate through the length of the string and calculate the following for each current substring window:
    - Lsub = Length of current substring window
    - Cmax = Count of max freq character in the window (fetch from map)
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
        
        // cout << maxLen << ": " << start << ", " << end << '\n';
        // cout << endl;

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