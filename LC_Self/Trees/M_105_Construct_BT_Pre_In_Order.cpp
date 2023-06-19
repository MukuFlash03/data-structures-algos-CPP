/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Solution(s): 
- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/3303497/c-detail-explain-diagram-simple-explanation-of-recursive-approach/


YouTube
NC - https://www.youtube.com/watch?v=ihj4IQGZ2zc
*/


/*

A. Recursive Approach

1. Use both the preorder and inorder arrays simultaneously for extracting different info about the binary tree.
2. Leftmost element of Pre array is always a root.
3. Find index of this element in In array and call it say, mid.
4. Now, all elements to the left of this element in In array belong to the L-subtree and similarly for the right ones.
5. Count of elements on either side, can be used to partition remaining elements in Pre array:
    - 1st L elements belong to L-subtree
    - Next R elements belong to R-subtree
6. Keep recursively creating subtrees using root nodes from Pre array and new subtree nodes from In array.
    

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


TreeNode *customTree(vector<int> &preorder, int preLow, int preHigh, vector<int> &inorder, int inLow, int inHigh) {
    if(preLow > preHigh || inLow > inHigh) 
        return nullptr;

    TreeNode *root = new TreeNode(preorder[preLow]);
    int mid = inLow;

    while(inorder[mid] != root->val) 
        mid++;
     
    int countLeft = mid - inLow;

    root->left = customTree(preorder, preLow + 1, preLow + countLeft, inorder, inLow, mid - 1);
    root->right = customTree(preorder, preLow + countLeft + 1, preHigh, inorder, mid + 1, inHigh);
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return customTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

int main() {

    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    // vector<int> preorder = {-1}, inorder = {-1};
    
    TreeNode* root = buildTree(preorder, inorder);
    printTree(root);
    cout << "\n";

    return 0;
}