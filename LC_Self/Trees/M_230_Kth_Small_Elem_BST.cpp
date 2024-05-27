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
#include "CustomTree.h"

using namespace std;

void preOrder(CustomTree::TreeNode* root, vector<int>&resPre) {
    if(!root) 
        return;
    resPre.push_back(root->val);
    preOrder(root->left, resPre);
    preOrder(root->right, resPre);
}

void postOrder(CustomTree::TreeNode* root, vector<int>&resPost) {
    if(!root) 
        return;
    postOrder(root->left, resPost);
    postOrder(root->right, resPost);
    resPost.push_back(root->val);
}

void inOrder(CustomTree::TreeNode* root, vector<int>&resIn) {
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

int kthSmallest(CustomTree::TreeNode* root, int k) {
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
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    cout << kthSmallest(root, k) << "\n";

    return 0;
}