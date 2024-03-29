/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/subtree-of-another-tree/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=E36O5SWp-LE
*/


/*

A. Recursive Approach

Time Complexity: O(A*B)

I. Function for SubTree

1. Identify base conditions:
    - If subtree null
        - Return true
    - If tree null
        - Return false

2. Recursively call function with OR of comparison between both L-subtrees and R-subtrees

II. Function for SameTree

1.  Identity base conditions:
    - If both null  
        - Return true
    - If either null OR both values do not match
        - Return false
2. Recursively call function with AND of comparison between both L-subtrees and R-subtrees

2. For each node, compare if current subtree matches given subtree.
3. If not, continue to next node in original tree.
4. Else, if same tree, then check if sub tree.


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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
        return true;
    if ( (p == nullptr || q == nullptr) || (p->val != q->val) )
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (subRoot == nullptr)
        return true;
    if (root == nullptr)
        return false;
    if (isSameTree(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
} 

int main() {

    // vector<string> nodesA = {"3","4","5","1","2"};
    // vector<string> nodesB = {"4","1","2"};

    vector<string> nodesA = {"3","4","5","1","2","null","null","null","null","0"};
    vector<string> nodesB = {"4","1","2"};

    TreeNode* rootA = levelOrderCreateTree(nodesA);
    TreeNode* rootB = levelOrderCreateTree(nodesB);
    cout << isSubtree(rootA, rootB) << "\n";

    return 0;
}