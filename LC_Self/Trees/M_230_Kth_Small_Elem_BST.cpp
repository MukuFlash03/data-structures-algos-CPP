/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Solution(s):
- https://leetcode.com/problems/kth-smallest-element-in-a-bst/solutions/3251944/simple-solution-easy-to-understand-approach/


YouTube
https://www.youtube.com/watch?v=5LUXSvjmGCw
*/


/*

A. Inorder Traversal

1. Perform inorder traversal.
2. Kth smallest element will be (k-1)th indexed element in the resultant traversal array.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
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

void preOrder(TreeNode* root, vector<int>&resPre) {
    if(!root) 
        return;
    resPre.push_back(root->val);
    preOrder(root->left, resPre);
    preOrder(root->right, resPre);
}

void postOrder(TreeNode* root, vector<int>&resPost) {
    if(!root) 
        return;
    postOrder(root->left, resPost);
    postOrder(root->right, resPost);
    resPost.push_back(root->val);
}

void inOrder(TreeNode* root, vector<int>&resIn) {
    if(!root) 
        return;
    inOrder(root->left, resIn);
    resIn.push_back(root->val);
    inOrder(root->right, resIn);
}

void printNodes(vector<int>& res) {
    for (const auto& elem : res)
        cout << elem << "\t";
    cout << "\n\n";
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> resIn, resPre, resPost;
    
    preOrder(root, resPre);
    inOrder(root, resIn);
    postOrder(root, resPost);

    printNodes(resPre);
    printNodes(resIn);
    printNodes(resPost);

    return resIn[k-1];
}

int main() {

    vector<string> nodes = {"3","1","4","null","2"};
    int k = 1;
    
    // vector<string> nodes = {"5","3","6","2","4","null","null","1"};
    // int k = 3;
    
    TreeNode* root = levelOrderCreateTree(nodes);
    cout << kthSmallest(root, k) << "\n";

    return 0;
}