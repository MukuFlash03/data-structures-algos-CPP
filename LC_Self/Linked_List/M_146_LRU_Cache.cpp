/*

Type: Linked List

//1 -> Global Node used; Not passed as function parameter
//2 -> Node* head passed as function parameter
//3 -> Node** head passed as function parameter, i.e. pointer to Node

Problem: https://leetcode.com/problems/lru-cache/
Solution(s): 
- https://www.romaglushko.com/blog/design-lru-cache/

YouTube
NC - https://www.youtube.com/watch?v=7ABFKPK2hD4

*/

/*

A. Optimal Approach

"Use"-d refers to both get and put operations.

1. Use a doubly linked list to maintain the order of the nodes.
2. Use a hashmap to store the key-value pairs.

- Node class has left pointer to store LRU node and right pointer to store MRU node.
- Node class has insert and remove methods to insert and remove nodes from the list.
    - Remove method working: 
        - Get the prev and next nodes of the node to be removed.
        - Set the next of prev to next and prev of next to prev.
    - Insert method working:
        - Get the prev and next nodes of the right node.
        - Set the next of prev to the node and prev of next to the node.
        - Set the prev and next of the node to prev and next.

- In the constructor, create a dummy left and right node.
- Get method working:
    - If the key is present in the cache, remove the node and insert it at the front.
- Put method working:
    - If the key is present in the cache, remove the node and delete it.
    - Insert the new node at the front.
    - If the cache size exceeds the capacity, remove the LRU node from the list and delete it.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include "CustomLL.h"

using namespace std;

class Node {
public:
    int k;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int value) : k(key), val(value), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int capacity = 0;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = this->right->prev;
        Node* next = this->right;
    
        prev->next = node;
        next->prev = node;

        node->prev = prev;
        node->next = next;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        this->left = new Node(0,0);
        this->right = new Node(0,0);

        this->left->next = this->right;
        this->right->prev = this->left;
    }
    
    int get(int key) {
        if (this->cache.find(key) != this->cache.end()) {
            // Move the node to the front = Remove from the list and add to the front
            remove(this->cache[key]);
            insert(this->cache[key]);
            return this->cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (this->cache.find(key) != this->cache.end()) {
            remove(this->cache[key]);
            delete this->cache[key];
        }

        this->cache[key] = new Node(key, value);
        insert(this->cache[key]);

        if (this->cache.size() > this->capacity) {
            Node* lru = this->left->next;
            remove(lru);
            this->cache.erase(lru->k);
            delete lru;
        }
    }

    void printCache() {
        for (const auto& elem : this->cache)
            cout << elem.first << " : " << elem.second->val << "\n";
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    CustomLL cll;

    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache->get(1) << "\t";    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache->get(2) << "\t";    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache->get(1) << "\t";    // return -1 (not found)
    cout << lRUCache->get(3) << "\t";    // return 3
    cout << lRUCache->get(4) << "\t";    // return 4   
    
    cout << "\n";
    lRUCache->printCache();

    return 0;
}