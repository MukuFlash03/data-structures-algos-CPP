/*
Problem: https://leetcode.com/problems/determine-if-two-strings-are-close
Solution(s): 
- https://leetcode.com/problems/determine-if-two-strings-are-close/solutions/4561223/beats-99-46-users-c-java-python-javascript-explained/?envType=daily-question&envId=2024-01-15

    
YouTube
https://www.youtube.com/watch?v=aNfMQ4qMBes
https://www.youtube.com/watch?v=-jXQK-UeChU
*/


/*

A. Hashmap Frequency Count

1. Return false is length of strings do not match.
2. Create frequency vectors for both strings.
3. If any character is present in one string but not in the other, return false.
4. Sort both vectors and compare. If any mismatch, return false.
5. Return true.

Trick is understanding the given operations:
1st one says that order of the characters does not matter.
2nd one says that matching frequency counts must be same when considering all characters
or, the same set of unique characters must be present in both strings.

With sets, less time efficient.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size())
        return false;

    vector<int> freqCtr1(26, 0);
    vector<int> freqCtr2(26, 0);
    set<int> charSet1;        
    set<int> charSet2;        

    for (int i = 0; i < word1.size(); i++) {
        freqCtr1[word1[i] - 'a']++;
        freqCtr2[word2[i] - 'a']++;
        charSet1.insert(word1[i]);
        charSet2.insert(word2[i]);
    }

    /* More time efficient 
    for (int i = 0; i < 26; i++) {
        if (
            (freqCtr1[i] == 0 && freqCtr2[i] != 0) ||
            (freqCtr1[i] != 0 && freqCtr2[i] == 0)
        )
            return false;
    }

    sort(freqCtr1.begin(), freqCtr1.end());
    sort(freqCtr2.begin(), freqCtr2.end());

    if (freqCtr1 == freqCtr2)
            return false;
    return true;
    */
    
    return ((charSet1 == charSet2) && (freqCtr1 == freqCtr2));
}

int main() {
    string word1 = "abc", word2 = "bca";
    // string word1 = "a", word2 = "aa";
    // string word1 = "cabbba", word2 = "abbccc";
    cout << closeStrings(word1, word2) << '\n';
    return 0;
}