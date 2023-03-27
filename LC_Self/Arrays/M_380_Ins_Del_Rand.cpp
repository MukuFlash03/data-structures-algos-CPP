/*
Type: Hash Map

Problem: https://leetcode.com/problems/insert-delete-getrandom-o1/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=j4KwhBziOpg

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
        map<int,int> numMap;
        vector<int> numList;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        bool flag = numMap.find(val) == numMap.end();
        if (flag) {
            numMap[val] = numMap.size();
            numList.push_back(val);
        }
        return flag;
    }
    
    bool remove(int val) {
        bool flag = numMap.find(val) != numMap.end();
        if (flag) {
            int idx = numMap[val];
            int lenL = numList.size();
            int lastL = numList[lenL-1];
            numList[idx] = lastL;
            numList.pop_back();
            numMap[lastL] = idx;
            numMap.erase(val);
        }
        return flag;
    }
    
    int getRandom() {
        int randIdx = rand() % numList.size();
        return numList[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main() {
    int val1 = 5, val2 = 10, val3 = 15;

    RandomizedSet* obj = new RandomizedSet();
    
    bool param_1 = obj->insert(val1);
    bool param_2 = obj->insert(val2);
    bool param_3 = obj->insert(val3);
    bool param_4 = obj->remove(val2);
    int param_5 = obj->getRandom();

    cout << param_1 << '\n';
    cout << param_2 << '\n';
    cout << param_3 << '\n';
    cout << param_4 << '\n';
    cout << param_5 << '\n';

    return 0;
}