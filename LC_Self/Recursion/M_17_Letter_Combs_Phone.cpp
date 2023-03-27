/*
Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=0snEunUacZY
*/


/*

Rough time complexity: O(n*4^n)
n: Length of each output string = len(digits)
4^n: Total number of output strings

A. Optimal Solution

Tracking variable: start

start: Need to maintain value with which we started current combination, 
    as we can only choose numbers greater than this value for adding more elements to the current combination

    - start serves as iterator through digits

comb: Need to keep track of current combination

k = len(digits)

1. Base condition:
    If len(combs) == k == len(digits)
        - Add combs to result
        - Return

2. Recursive condition
    - Get the string mapping for current number in digits
    - This string becomes currStr
    - For each char in currStr, recursively call func() with (start+1)
        - Push current char to combs
        - This causes string mapping for next char in digits to be obtained
            and create combinations of previous char's string mappings with next one's
        - Pop added current char


B. Extension of M_77_Combinations

W.r.t recurCombine(int start, int n, int k)

1. k = len(digits)
2. lets = combined string of chars for each digit in digits
3. n = len(lets)
4. Same logic as recurCombine, starting with first char of lets and going till last.

Incorrect logic: 
- Includes char combinations from same number as well
    - For e.g. 23 -> 2 = "abc", 3 = "def"
    - Gives "ab", "ac" along with "ad", "ae", "af"
    - Should only give the latter.

- Incorrect backtracking tree created



*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string combs;
vector<string> result;

map<int, string> create_map() {
    map<int, string> letMap;
    letMap[2] = "abc";
    letMap[3] = "def";
    letMap[4] = "ghi";
    letMap[5] = "jkl";
    letMap[6] = "mno";
    letMap[7] = "pqrs";
    letMap[8] = "tuv";
    letMap[9] = "wxyz";
    return letMap;
}

map<int, string> letters = create_map();

void recurCombine(int start, string digits, int k) {

    if (combs.size() == k) {
        result.push_back(combs);
        return;
    }
    int idx = digits[start]-'0';
    string curr = letters[idx];
    for (auto ch : curr) {
        combs.push_back(ch);
        recurCombine(start+1,digits,k);
        combs.pop_back();
    }
}


vector<string> letterCombinations(string digits) {
    int k = digits.length();
    if (digits != "")
        recurCombine(0,digits,k);
    return result;
}



int main() {

    string digits = "23";
    // string digits = "";
    // string digits = "2";

    vector<string> result = letterCombinations(digits);

    for (const auto &elem : result) {
        for (const auto &elem2 : elem) 
            cout << elem2 << ',';
        cout << '\t';
    }
    cout << '\n';


    return 0;
}



// ---------------------------
// Solution B

/*
void recurCombine(int start, string lets, int k) {

    int n = lets.size();

    if (combs.size() == k) {
        result.push_back(combs);
        return;
    }
    for (int i = start; i < n; i++) {
        combs.push_back(lets[i]);
        recurCombine(i+1,lets,k);
        combs.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    string lets = "";
    int k = digits.length();
    for (auto i : digits)
        lets += letters[i - '0'];

    // cout << lets << '\n';
    recurCombine(0,lets,k);
    return result;
}
*/