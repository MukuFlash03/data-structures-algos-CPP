/*
Problem: https://leetcode.com/problems/implement-queue-using-stacks/
Solution(s): 
- https://www.geeksforgeeks.org/queue-using-stacks/
- https://leetcode.com/problems/implement-queue-using-stacks/solutions/2916636/easy-and-simple-c-solutions/

*/


/*


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;


class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    int val;
    MyQueue() {
        st1 = {};
        st2 = {};
        val = -1;
    }

    void pre() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
    }

    void post() {
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if (st1.empty() && st2.empty())
            return -1;
        
        pre();
        val = st2.top();
        st2.pop();
        post();

        return val;
    }
    
    int peek() {
        if (st1.empty() && st2.empty())
            return -1;
        
        pre();
        val = st2.top();
        post();

        return val;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

struct Results {
    int num = -1;
    int flag = -1;
};

int main() {

    // vector<string> inputCmds = {"MyQueue", "push", "push", "peek", "pop", "empty"};
    // vector<int> inputVals = {{}, {1}, {2}, {}, {}, {}};

    vector<string> inputCmds = {"MyQueue", "push", "push", "peek", "pop", "peek", "pop", "empty"};
    vector<int> inputVals = {{}, {1}, {2}, {}, {}, {}, {}, {}};

    MyQueue* obj = new MyQueue();

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
        else if (*itC == "peek")
            next.num = obj->peek();
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

