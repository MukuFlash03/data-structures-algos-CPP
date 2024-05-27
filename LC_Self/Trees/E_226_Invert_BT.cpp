/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/invert-binary-tree/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=OnSn2XEQ4MY
*/


/*

A. Swapping Nodes

1. Use a temp node to swap the left and right nodes.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomTree.h"

using namespace std;

CustomTree::TreeNode* invertTree(CustomTree::TreeNode* root) {
    if (root == nullptr)
        return NULL;
    
    CustomTree::TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
} 


int main() {

    vector<string> nodes = {"3","9","20","null","null","15","7"};
    // vector<string> nodes = {"1","null","2"};
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    CustomTree::TreeNode* inverted = invertTree(root);
    ctree.printTree(root);
    cout << "\n";
    ctree.printTree(inverted);
    cout << "\n";

    return 0;
}