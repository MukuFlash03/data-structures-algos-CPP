/*
Problem: https://leetcode.com/problems/generate-parentheses/
Solution(s): 
- https://leetcode.com/problems/generate-parentheses/solutions/3064146/easy-c-recursive-and-back-tracking-solutions/

YouTube
NC - https://www.youtube.com/watch?v=s9fokUqJ76A
*/


/*

A. Optimal Solution

Tracking variables: open, close

1. Stop adding parenthesis only if close == open == n
    Push the current string into result vector
    Return
2. Add opening parenthesis only if open < n.
    Pop stack
3. Add closing parenthesis only if close < open.
    Pop stack
4.  Here, add current stack of chars "()"" to result

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<char> pars;
vector<string> result;

void recurGenerate(int open, int close, int n) {

    if ( (open == close) && (open == n) ) {
        string str(pars.begin(), pars.end());
        result.push_back(str);
        return;
    }
    if (open < n) {
        pars.push_back('(');
        recurGenerate(open+1,close,n);
        pars.pop_back();
    }
    if (close < open) {
        pars.push_back(')');
        recurGenerate(open,close+1,n);
        pars.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    recurGenerate(0,0,n);
    return result;
}

int main() {

    int n = 3;
    // int n = 1;

    vector<string> result = generateParenthesis(n);

    for (const auto &elem : result)
        cout << elem << '\t';
    cout << '\n';

    return 0;
}