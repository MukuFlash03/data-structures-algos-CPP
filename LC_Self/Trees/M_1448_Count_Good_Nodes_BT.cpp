/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
Solution(s):

YouTube
NC - https://www.youtube.com/watch?v=7cp5imvDzl4
*/


/*

A. Recursive Approach

0. Initial / Return dfs call with root and INT_MIN.
1. If root is null, return 0.
2. If root is greater than or equal to currMax, increment count.
3. Update currMax to max of currMax and root->val.
4. Recursively call dfs for left and right subtrees, passing the updated count (+=) and currMax.
5. Return the total count of good nodes.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomTree.h"

using namespace std;

int dfs(CustomTree::TreeNode* root, int currMax) {
    if (root == nullptr)
        return 0;
    
    int res = root->val >= currMax ? 1 : 0;

    currMax = max(currMax, root->val);

    res += dfs(root->left, currMax);
    res += dfs(root->right, currMax);
    
    return res;
}

int goodNodes(CustomTree::TreeNode* root) {
    return dfs(root, INT_MIN);
}

int main() {

    vector<string> nodes = {"3","1","4","3","null","1","5"};
    // vector<string> nodes = {"3","3","null","4","2"};
    // vector<string> nodes = {"1"};
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    cout << goodNodes(root) << "\n";

    return 0;
}