/*

Type: Memoization, Bottom-up

Problem: hhttps://leetcode.com/problems/longest-common-subsequence/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=Ua0GhsJSlWM
*/


/*

A. Basic DP Approach

2D matrix
If matching character, add 1 to diagonal element
Else, max of left and top element

*/


#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[len1][len2];
}

int main() {

    string text1 = "abcde", text2 = "ace";
    // string text1 = "abc", text2 = "abc";
    // string text1 = "abc", text2 = "def";

    cout << longestCommonSubsequence(text1, text2) << "\n";

    return 0;
}