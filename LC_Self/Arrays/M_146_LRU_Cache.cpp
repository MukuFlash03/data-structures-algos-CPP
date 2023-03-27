/*
Type: Hash Map

Problem: https://leetcode.com/problems/lru-cache/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=7ABFKPK2hD4

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
private:
    int key;
    int val;

public:
    Node(int k, int v) {
        key = k;
        val = v;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main() {
    int key = 2, value = 10;
    int capacity = 5;

    LRUCache* obj = new LRUCache(capacity);
    
    int param_1 = obj->get(key);
    obj->put(key,value);

    cout << param_1 << '\n';

    return 0;
}