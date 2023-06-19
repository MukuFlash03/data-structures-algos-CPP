/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=gs2LMfuOR9k
*/


/*

A. Recursive Approach

Time Complexity = O(logn) = Height of tree
    - Visiting just one of the nodes on each level

- Set currNode to the root node.
- Keep iterating till currNode is not null.
    - If both p,q are greater than currNode
        - Set currNode to right subtree of currNode
    - Else if both p,q are lower than currNode
        - Set currNode to left subtree of currNode
    - Else break
- Return currNode


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    TreeNode* currNode = root;

    while (currNode != nullptr) {
        if ( (p->val > currNode->val) && (q->val > currNode->val) )
            currNode = currNode->right;
        else if ( (p->val < currNode->val) && (q->val < currNode->val) )
            currNode = currNode->left;
        else
            break;
    }
    return currNode;
}


int main() {

    vector<string> nodes = {"6","2","8","0","4","7","9","null","null","3","5"};
    int p = 2, q = 8;
    // int p = 2, q = 4;

    // vector<string> nodes = {"2","1"};
    // int p = 2, q = 1;
    
    TreeNode* root = levelOrderCreateTree(nodes);
    // TreeNode* lca = lowestCommonAncestor(root, p, q);
    // cout << lca->val << "\n";

    return 0;
}