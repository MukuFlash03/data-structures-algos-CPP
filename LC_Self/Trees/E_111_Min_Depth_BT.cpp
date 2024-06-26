/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/minimum-depth-of-binary-tree/
Solution(s): 
- https://leetcode.com/problems/minimum-depth-of-binary-tree/solutions/1174041/c-bfs-level-order-traversal-recursion-dfs-4-easy-solutions/
- https://leetcode.com/problems/minimum-depth-of-binary-tree/solutions/3266364/easiest-typescript-solution-dfs/
- https://leetcode.com/problems/minimum-depth-of-binary-tree/solutions/3135655/easy-beginner-friendly-recursion-code-with-explanation-c/


YouTube
NC - 
*/


/*

A. Recursive Depth-first search

Case 1
When your root node has both left and right node then you simply find the minimum of the left subtree and right subtree and add 1 to it to count the root node

Case 2
When you either have left or right node but not both. Then you simply return the maximum height of the available subtree.


B. Iterative Breadth-first search

1. Perform BFS while calculating depth.
2. If both left and right nodes are null, return depth.

C. Iterative Depth-first search

1. Wrong answer for input: [1,2,3,4,5]: expected 2, got 3.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include "CustomTree.h"

using namespace std;

// Recursion / DFS - 2

// int minDepthA(TreeNode* root) {
//     if (root == nullptr)
//         return 0;
//     if (root->left && root->right)  
//         return min(minDepthA(root->left), minDepthA(root->right))+1;
//     return max(minDepthA(root->left), minDepthA(root->right))+1;
// }


// BFS
int minDepthB(CustomTree::TreeNode* root) {
    if (root == nullptr)
        return 0;
    
    queue<CustomTree::TreeNode*> qNodes;
    qNodes.push(root);
    int depth = 0;

    while (!qNodes.empty()) {
        int len = qNodes.size();
        depth++;
        while (len--) {
            CustomTree::TreeNode* node = qNodes.front();
            qNodes.pop();
            
            // cout << node->val << "," << depth << "\t";
            if (node->left != nullptr)
                qNodes.push(node->left);
            if (node->right != nullptr)
                qNodes.push(node->right);

            if (!node->left && !node->right)
                return depth;
        }
    }
    return depth;
}


// int minDepthC(TreeNode* root) {

//     if (root == nullptr)
//         return 0;

//     int left = minDepthC(root->left) + 1;
//     int right = minDepthC(root->right) + 1;

//     if (!root->left) 
//         return right;
//     if (!root-right) 
//         return left;

//     return min(left, right);
// }


int main() {

    // vector<string> nodes = {"3","9","20","null","null","15","7"};
    // vector<string> nodes = {"2","null","3","null","4","null","5","null","6"};
    vector<string> nodes = {"1","2","3","4","5"};

    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    // printTree(node);
    // cout << "Recursive DFS: " << minDepthA(root) << "\n";
    cout << "Iterative BFS: " << minDepthB(root) << "\n";
    // cout << "Iterative DFS: " << minDepthC(root) << "\n";

    return 0;
}