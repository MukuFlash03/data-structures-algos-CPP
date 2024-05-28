/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
Solution(s):

YouTube
NC - https://www.youtube.com/watch?v=Hr5cWUld4vU
*/


/*

A. Recursive Approach

Idea:
1. Use DFS.
2. Go via left subtree and find maximum path sum without splitting.
3. Go via right subtree and find maximum path sum without splitting.
4. Splitting is allowed if any ancestor node hasn't split, else splitting not allowed if already split at higher level.
5. At the current node:
    - If splitting is allowed, total path sum is:
        = Left path sum + Current node value + Right path sum
        This is the value added to result, if greater than current result.
            - Res stores max of currMax and res.
    - If splitting is not allowed, total path sum:
        = Current node value + Max of (Left path sum, Right path sum)
        This is the value returned by DFS for left and right subtrees.
        This is because, the reason we're calculating max of left and right is because we split from current node (inherently as we did dfs(left) and dfs(right)).
        So, we can't split further as we've already split at higher level, so we take max of left and right path sums.
6. In case of -ve node values, we can choose not to include in path by taking max of 0 and node value.
7. Return maximum path sum.


Essentially, at each point we are calculating two things:
- Subtree sum including current root node.
- Max path sum including current root node going either via left or via right.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomTree.h"

using namespace std;

int dfs(CustomTree::TreeNode* root, int& res) {
    if (root == nullptr)
        return 0;

    int leftMax = dfs(root->left, res);
    int rightMax = dfs(root->right, res);

    leftMax = max(leftMax, 0);
    rightMax = max(rightMax, 0);

    int currMax = leftMax + root->val + rightMax;
    res = max(res, currMax);

    return root->val + max(leftMax, rightMax);
}

int maxPathSum(CustomTree::TreeNode* root) {
    int res = INT_MIN;
    dfs(root, res);
    return res;
}

int main() {

    // vector<string> nodes = {"1", "2", "3"};
    vector<string> nodes = {"-10", "9", "20", "null", "null", "15", "7"};
    // vector<string> nodes = {"-3"};
    // vector<string> nodes = {"1"};
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    cout << maxPathSum(root) << "\n";

    return 0;
}