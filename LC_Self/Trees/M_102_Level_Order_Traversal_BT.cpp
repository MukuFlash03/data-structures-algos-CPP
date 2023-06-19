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

using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


void createTree(TreeNode* node, int i, vector<string>& arr) {
    if (node != nullptr) {
        if (2 * i + 1 < arr.size()) {
            if (arr[2 * i + 1] == "null")
                node->left = nullptr;
            else
                node->left = new TreeNode(stoi(arr[2 * i + 1]));
            createTree(node->left, 2 * i + 1, arr);
        }

        if (2 * i + 2 < arr.size()) {
            if (arr[2 * i + 2] == "null")
                node->right = nullptr;
            else
                node->right = new TreeNode(stoi(arr[2 * i + 2]));
            createTree(node->right, 2 * i + 2, arr);
        }
    }
}

TreeNode* levelOrderCreateTree(vector<string>& arr) {
    if (arr.size() == 0)
        return nullptr;
    
    TreeNode *root = new TreeNode(stoi(arr[0]));
    createTree(root, 0, arr);

    return root;
}

void printTree(TreeNode* root) { 
    if(root == nullptr) {
        // cout << "null\t";
        return;
    }
    cout << root->val << "\t";
    printTree(root->left);
    printTree(root->right);
} 

vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> levels;

    if (root == nullptr)
        return levels;
    
    queue<TreeNode*> qNodes;
    qNodes.push(root);

    while (!qNodes.empty()) {

        vector<int> level;
        // for (int i = 0; i < qNodes.size(); i++) {
        int len = qNodes.size();
        while (len--) {
            TreeNode* node = qNodes.front();
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
    
    TreeNode* root = levelOrderCreateTree(nodes);
    // printTree(node);
    
    vector<vector<int>> levels = levelOrder(root);

    for (const auto& level : levels)
        for (const auto& elem: level)
            cout << elem << "\t";
        cout << "\n";

    return 0;
}