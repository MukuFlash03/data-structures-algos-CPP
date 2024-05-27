/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=6ZnyEApgFYg
*/


/*

A. Iterative Breadth-first search

Time Complexity: O(n)
Memory Complexity: O(n)

1. Use a queue to store nodes in PreOrder: Rlr.
2. Keep popping and adding nodes as you encounter them.
3. Increment depth for each level, not for each node.
4. Return when queue is empty and tree has been traversed.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include "CustomTree.h"

using namespace std;

vector<vector<int>> levelOrder(CustomTree::TreeNode* root) {

    vector<vector<int>> levels;

    if (root == nullptr)
        return levels;
    
    queue<CustomTree::TreeNode*> qNodes;
    qNodes.push(root);

    while (!qNodes.empty()) {

        vector<int> level;
        // for (int i = 0; i < qNodes.size(); i++) {
        int len = qNodes.size();
        while (len--) {
            CustomTree::TreeNode* node = qNodes.front();
            qNodes.pop();

            if (node != nullptr)
                level.push_back(node->val);

            if (node->left != nullptr)
                qNodes.push(node->left);
            if (node->right != nullptr)
                qNodes.push(node->right);
        }

        if (!level.empty())
            levels.push_back(level);
    }
    return levels;
}

int main() {

    vector<string> nodes = {"3","9","20","null","null","15","7"};
    // vector<string> nodes = {"1"};
    // vector<string> nodes = {};
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    // printTree(node);
    
    vector<vector<int>> levels = levelOrder(root);

    for (const auto& level: levels) {
        for (const auto& elem: level)
            cout << elem << "\t";
    }
    cout << "\n";

    return 0;
}