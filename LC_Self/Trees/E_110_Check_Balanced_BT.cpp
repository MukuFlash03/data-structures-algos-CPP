/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/balanced-binary-tree/
Solution(s): 
- Queue: https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/3191132/recursive-and-iterative-solutions/
- Stack: https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/1125292/c-dfs-bfs-4-approaches-time-o-n-space-o-h/
         https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/447373/c-dfs-iterative-solution/

YouTube
NC - https://www.youtube.com/watch?v=QfJsau0ItOY
*/


/*

A. Bottom-up Approach

Time Complexity: O(n)

1. Start checking from bottom-most leaf nodes/subtrees whether they are balanced or not.
2. If root is null, return true.
3. Recursive call to calculate depth of L and R subtrees.
4. Store boolean for AND of these conditions:
    - Difference in depths of L and R subtrees is LTE 1
    - L and R subtrees themselves are balanced
5. Return this bool value.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

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

pair<bool,int> maxDepth(TreeNode* node) {
    if (node == nullptr)
        return {true, 0};

    pair<bool,int> left = maxDepth(node->left);
    pair<bool,int> right = maxDepth(node->right);

    pair<bool,int> result;
    result.first = (abs(left.second - right.second) <= 1) && left.first && right.first;
    result.second = 1 + max(left.second, right.second);

    return result;
}

bool isBalanced(TreeNode* root) {
    return maxDepth(root).first;
}

int main() {

    vector<string> nodes = {"3","9","20","null","null","15","7"};
    // vector<string> nodes = {"1","2","2","3","3","null","null","4","4"};
    // vector<string> nodes = {};
    
    TreeNode* root = levelOrderCreateTree(nodes);
    // printTree(node);
    cout << isBalanced(root) << "\n";

    return 0;
}