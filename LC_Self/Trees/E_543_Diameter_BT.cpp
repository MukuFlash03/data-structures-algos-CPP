/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/diameter-of-binary-tree/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=bkxqA8Rfv04
*/


/*

A. DFS Approach

1. Use the dfs logic to get height of subtrees.
2. Diameter = Height of L-subtree + Height of R-Subtree
3. Height itself is calculated as 1 + max of Height of L-subtree and Height of R-subtree.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

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

int dfs(TreeNode* node, int& dia) {
    if (node == nullptr)
        return 0;

    int left = dfs(node->left, dia);
    int right = dfs(node->right, dia);

    dia = max(dia, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int dia = 0;
    dfs(root, dia);
    return dia;
} 


int main() {

    vector<string> nodes = {"1","2","3","4","5"};
    // vector<string> nodes = {"1","2"};
    
    TreeNode* root = levelOrderCreateTree(nodes);
    cout << diameterOfBinaryTree(root) << "\n";

    return 0;
}