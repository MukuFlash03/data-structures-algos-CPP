/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/validate-binary-search-tree/
Solution(s):
- https://leetcode.com/problems/validate-binary-search-tree/solutions/2982339/optimized-approach/ 

YouTube
NC - https://www.youtube.com/watch?v=s6ATEkipzow
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
#include "CustomTree.h"

using namespace std;

bool isValidNode(CustomTree::TreeNode* node, long left, long right) {
    if (node == nullptr)
        return true;

    if (!((left < node->val) && (node->val < right)))
        return false;

    return isValidNode(node->left, left, node->val) && isValidNode(node->right, node->val, right);
}

bool isValidBST(CustomTree::TreeNode* root) {
    return isValidNode(root, LONG_MIN, LONG_MAX);
}


int main() {

    vector<string> nodes = {"2","1","3"};
    // vector<string> nodes = {"5","1","4","null","null","3","6"};
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    cout << isValidBST(root) << "\n";

    return 0;
}