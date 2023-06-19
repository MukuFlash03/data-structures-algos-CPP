/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/
Solution(s): 
- Queue: https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/3191132/recursive-and-iterative-solutions/
- Stack: https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/1125292/c-dfs-bfs-4-approaches-time-o-n-space-o-h/
         https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/447373/c-dfs-iterative-solution/

YouTube
NC - https://www.youtube.com/watch?v=hTM3phVI6YQ
*/


/*

A. Recursive Depth-first search

1. Get to the current node.
2. Depth for current node = 1 + max(depth of L-tree, depth of R-tree).


B. Iterative Breadth-first search

1. Use a queue to store nodes in PreOrder: Rlr.
2. Keep popping and adding nodes as you encounter them.
3. Increment depth for each level, not for each node.
4. Return when queue is empty and tree has been traversed.


C. Iterative Depth-first search

1. Use a stack to store nodes in PreOrder: Rlr.
2. Keep popping and adding nodes as you encounter them.
3. For each node added to stack, also add its depth.
4. Update max depth if current depth is greater than depth.
5. Append each node's children.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>

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

int maxDepthA(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return 1 + max(maxDepthA(root->left), maxDepthA(root->right));
} 

int maxDepthB(TreeNode* root) {
    if (root == nullptr)
        return 0;
    
    queue<TreeNode*> qNodes;
    qNodes.push(root);
    int depth = 0;

    while (!qNodes.empty()) {
        int len = qNodes.size();
        while (len--) {
            TreeNode* node = qNodes.front();
            qNodes.pop();
            
            cout << node->val << "," << depth << "\t";
            if (node->left != nullptr)
                qNodes.push(node->left);
            if (node->right != nullptr)
                qNodes.push(node->right);
        }
        depth++;
    }
    return depth;
} 

int maxDepthC(TreeNode* root) {
    if (root == nullptr)
        return 0;
    
    stack<pair<TreeNode*,int>> sNodes;
    sNodes.push({root,0});
    int depth = 0, currDepth = 0;

    while (!sNodes.empty()) {
        
        TreeNode* node = sNodes.top().first;
        currDepth = sNodes.top().second;
        sNodes.pop();

        depth = max(depth,currDepth);
        
        cout << node->val << "," << depth << "\t";
        if (node->right != nullptr)
            sNodes.push({node->right,currDepth+1});
        if (node->left != nullptr)
            sNodes.push({node->left,currDepth+1});
    }
    return ++depth;
} 

// int maxDepthC(TreeNode* root) {
    //     if (root == nullptr)
    //         return 0;
    
    // stack<pair<TreeNode*,int>> sNodes;
    // sNodes.push({root,1});
    // int depth = 0, currDepth = 0;

    // while (!sNodes.empty()) {
        
    //     TreeNode* node = sNodes.top().first;
    //     currDepth = sNodes.top().second;
    //     sNodes.pop();

    //     depth = max(depth,currDepth);
    //     if (node->left != nullptr)
    //         sNodes.push({node->left,currDepth+1});
    //     if (node->right != nullptr)
    //         sNodes.push({node->right,currDepth+1});
    //     if (node->left != nullptr)
    //         sNodes.push({node->left,currDepth+1});
    // }
    // return depth;
// } 


int main() {

    vector<string> nodes = {"3","9","20","null","null","15","7"};
    // vector<string> nodes = {"1","null","2"};
    
    TreeNode* root = levelOrderCreateTree(nodes);
    // printTree(node);
    cout << "Recursive DFS: " << maxDepthA(root) << "\n";
    cout << "Iterative BFS: " << maxDepthB(root) << "\n";
    cout << "Iterative DFS: " << maxDepthC(root) << "\n";

    return 0;
}