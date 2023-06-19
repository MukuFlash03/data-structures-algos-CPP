/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Solution(s): 
- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solutions/2976231/c-easy-to-understand/

YouTube
https://www.youtube.com/watch?v=VG5w_VVAgH4
*/


/*

A. Recursive Approach

1. If current root node is same as either p or q or is NULL, then return it.
2. Recursive calls for left and right subtrees.
3. If left is NULL, return right and vice versa.
4. Else return current root node.

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
    if(root == NULL || root == p || root == q) 
        return root;

    TreeNode* left  = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL) 
        return right;
    else if (right == NULL) 
        return left;
    else 
        return root;
}


int main() {

    vector<string> nodes = {"3","5","1","6","2","0","8","null","null","7","4"};
    int p = 5, q = 1;
    // int p = 5, q = 4;
    
    TreeNode* root = levelOrderCreateTree(nodes);
    // TreeNode* lca = lowestCommonAncestor(root, p, q);
    // cout << lca->val << "\n";

    return 0;
}