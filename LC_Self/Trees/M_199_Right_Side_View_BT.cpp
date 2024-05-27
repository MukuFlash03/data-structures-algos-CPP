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
#include "CustomTree.h"

using namespace std;

vector<int> rightSideView(CustomTree::TreeNode* root) {

    vector<int> rightView;

    if (root == nullptr)
        return rightView;

    queue<CustomTree::TreeNode*> qNodes;
    qNodes.push(root);

    while (!qNodes.empty()) {
        int len = qNodes.size();
        CustomTree::TreeNode* rightNode;
        while(len--) {
            CustomTree::TreeNode* node = qNodes.front();
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
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    // ctree.printTree(node);
    
    vector<int> rightView = rightSideView(root);
    
    for (const auto& elem: rightView)
        cout << elem << "\t";
    cout << "\n";

    return 0;
}