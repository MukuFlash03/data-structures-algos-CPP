/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/binary-tree-right-side-view/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=d4zLyf32e3I
*/


/*

A. Iterative Breadth-first search

Time Complexity: O(n)
Memory Complexity: O(n)

1. Perform level order traversal or BFS using a queue.
2. For each level, fetch the right-most node.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

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

vector<int> rightSideView(TreeNode* root) {

    vector<int> rightView;

    if (root == nullptr)
        return rightView;

    queue<TreeNode*> qNodes;
    qNodes.push(root);

    while (!qNodes.empty()) {
        int len = qNodes.size();
        TreeNode* rightNode;
        while(len--) {
            TreeNode* node = qNodes.front();
            rightNode = node;
            qNodes.pop();

            if (node->left != nullptr)
                qNodes.push(node->left);
            if (node->right != nullptr)
                qNodes.push(node->right);
        }
        rightView.push_back(rightNode->val);
    }
    return rightView;
}


int main() {

    vector<string> nodes = {"1","2","3","null","5","null","4"};
    // vector<string> nodes = {"1","null","3"};
    // vector<string> nodes = {};
    
    TreeNode* root = levelOrderCreateTree(nodes);
    // printTree(node);
    
    vector<int> rightView = rightSideView(root);
    
    for (const auto& elem: rightView)
        cout << elem << "\t";
    cout << "\n";

    return 0;
}