/*
Problem: https://leetcode.com/problems/valid-parentheses/
Solution(s): 
- https://leetcode.com/problems/valid-parentheses/solutions/3100615/c-solution-using-stack-explained/

YouTube
NC - https://www.youtube.com/watch?v=WTzjTskDFMg
*/


/*


A. Optimal Solution

Check comments.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<map>


using namespace std;

string combs;
vector<string> result;

map<char, char> create_map() {
    map<char, char> letMap;
    letMap[')'] = '(';
    letMap[']'] = '[';
    letMap['}'] = '{';
    return letMap;
}

// map<char, char> braces = create_map();

bool isValid(string s) {

    stack<char> pile;
 
    for (const auto& ch : s) {
        // char ch = s[i];

        // if opening bracket then push into the stack 
        if (ch == '(' || ch == '{' || ch == '[')
            pile.push(ch);
        else {
            // if a closing bracket then we compare with the top of the stack 
            // while comparing with top of stack we have 2 cases 
            // the stack can be empty or the stack is not empty 
            if (!pile.empty()) {
                char top = pile.top();
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) 
                        pile.pop();    // if matches then pop 
                    else 
                        return false;
            }
            else
                return false;
            // if stack is empty and we get a closing bracket means the string is unbalanced     
        }
    }

    // in the end if the stack is empty -- meaning there is no opening bracket present in the stack -- meaning all opening brackets have found
    // their corresponding closing bracket and have been popped then we return true 
    if (pile.empty())
        return true; 
    return false;
}

int main() {

    // string s = "()";
    string s = "()[]{}";
    // string s = "(]";

    cout << isValid(s) << "\n";

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