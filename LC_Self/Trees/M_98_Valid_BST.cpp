/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/validate-binary-search-tree/
Solution(s):
- https://leetcode.com/problems/validate-binary-search-tree/solutions/2982339/optimized-approach/ 

YouTube
https://www.youtube.com/watch?v=s6ATEkipzow
*/


/*

A. Recursive Approach

Time Complexity: O(n)

1. Set root node's lower and upper bounds as (-inf, +inf)
2. While traversing to child nodes, subtrees get bounds from parent nodes
    - L-subtree: upper bound fetched from parent node
    - R-subtree: lower bound fetched from parent node
3. Bounds may be updated if required.
4. Whenver, not satisfied, that current node is not in its right position in the BST.
5. Hence, BST is not valid.


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

bool isValidNode(TreeNode* node, long left, long right) {
    if (node == nullptr)
        return true;

    if (!((left < node->val) && (node->val < right)))
        return false;

    return isValidNode(node->left, left, node->val) && isValidNode(node->right, node->val, right);
}

bool isValidBST(TreeNode* root) {
    return isValidNode(root, LONG_MIN, LONG_MAX);
}


int main() {

    vector<string> nodes = {"2","1","3"};
    // vector<string> nodes = {"5","1","4","null","null","3","6"};
    
    TreeNode* root = levelOrderCreateTree(nodes);
    cout << isValidBST(root) << "\n";

    return 0;
}