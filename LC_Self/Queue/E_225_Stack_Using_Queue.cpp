/*
Problem: https://leetcode.com/problems/implement-stack-using-queues/
Solution(s): 
- 

*/


/*


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;


class MyStack {
public:
    queue<int> qu1;
    queue<int> qu2;
    int val;
    MyStack() {
        qu1 = {};
        qu2 = {};
        val = -1;
    }

    void pre() {
        if (qu2.empty()) {
            while (qu1.size() != 1) {
                qu2.push(qu1.front());
                qu1.pop();
            }
        }
    }

    void post() {
        queue<int> q = qu1;
        qu1 = qu2;
        qu2 = q;
    }
    
    void push(int x) {
        qu1.push(x);
    }
    
    int pop() {
 
        if (qu1.empty() && qu2.empty())
            return -1;
        
        pre();
        val = qu1.front();
        qu1.pop();
        post();

        return val;
    }
    
    int top() {
        if (qu1.empty() && qu2.empty())
            return -1;
        
        pre();
        val = qu1.front();
        qu1.pop();
        qu2.push(val);
        post();

        return val;
    }
    
    bool empty() {
        return qu1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

struct Results {
    int num = -1;
    int flag = -1;
};

int main() {

    vector<string> inputCmds = {"MyStack", "push", "push", "top", "pop", "empty"};
    vector<int> inputVals = {{}, {1}, {2}, {}, {}, {}};

    // vector<string> inputCmds = {"MyQueue", "push", "push", "peek", "pop", "peek", "pop", "empty"};
    // vector<int> inputVals = {{}, {1}, {2}, {}, {}, {}, {}, {}};

    MyStack* obj = new MyStack();

    vector<string>::iterator itC = inputCmds.begin()+1;
    vector<int>::iterator itV = inputVals.begin()+1;

    vector<Results> result;
    Results first;
    result.push_back(first);

    for (; itC != inputCmds.end(), itV != inputVals.end(); ++itC, ++itV) {
        
        Results next;

        if (*itC == "push")
            obj->push(*itV);
        else if (*itC == "pop")
            next.num = obj->pop();
        else if (*itC == "top")
            next.num = obj->top();
        else if (*itC == "empty")
            next.flag = obj->empty();

        // cout << *itC << "\t";
        // cout << next.flag << "\n";

        result.push_back(next);
    }


    for (const auto& elem : result) {
        if (elem.num == -1 && elem.flag == -1)
            cout << "null" << "\t";
        else if (elem.num != -1 && elem.flag == -1)
            cout << elem.num << "\t";
        else if (elem.flag != -1)
            cout << elem.flag << "\t";

        // cout << elem.num << "\t" << elem.flag << "\n";
    }
        
    cout << "\n";


    return 0;
}

