/*
Problem Statement
Given are two strings S and T.
Let us change some of the characters in S so that T will be a substring of  S.
At least how many characters do we need to change?
Here, a substring is a consecutive subsequence. 
For example, xxx is a substring of yxxxy, but not a substring of xxyxx.

Constraints

The lengths of S and T are each at least 1 and at most 1000. 
The length of T is at most that of S. 
S and T consist of lowercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

int isSub (string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int i,j,ans = INT_MAX, count = 0;
    for (i = 0; i <= m-n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
            if (s1[i+j] != s2[j])
                count++;

        ans = min(ans,count);
    }
    return ans;
}

int main()
{   
    string s,t;
    getline(cin,s);
    getline(cin,t);

    cout << isSub(s,t) << endl;
    return 0;
}
