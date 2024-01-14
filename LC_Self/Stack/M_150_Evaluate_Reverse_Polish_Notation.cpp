/*
Problem: https://leetcode.com/problems/evaluate-reverse-polish-notation
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=iu0082c4HDE
*/


/*


A. Optimal Solution

Use stack to perform operations every time an operator is encountered.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

int calc(char op, int a, int b) {
    int ans = 0;
    switch(op) {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            ans = a / b;
            break;
        default:
            ans = 0;
    }
    return ans;
}

int evalRPN(vector<string>& tokens) {
    stack<int> stNum;
    int a, b, ans;

    for (const auto& elem : tokens) {
        if (elem == "+" || 
            elem == "-" || 
            elem == "*" || 
            elem == "/") {
            b = stNum.top();
            stNum.pop();
            a = stNum.top();
            stNum.pop();
            ans = calc(elem[0], a, b);
            stNum.push(ans);
        }
        else
            stNum.push(stoi(elem));
    }
    return stNum.top();
}

int main() {

    vector<string> tokens = {"2","1","+","3","*"};
    // vector<string> tokens = {"4","13","5","/","+"};
    // vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << evalRPN(tokens) << "\n";

    return 0;
}