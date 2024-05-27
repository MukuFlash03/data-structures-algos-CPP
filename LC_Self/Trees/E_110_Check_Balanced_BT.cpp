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
#include<vector>
#include "CustomTree.h"

using namespace std;

pair<bool,int> maxDepth(CustomTree::TreeNode* node) {
    if (node == nullptr)
        return {true, 0};

    pair<bool,int> left = maxDepth(node->left);
    pair<bool,int> right = maxDepth(node->right);

    pair<bool,int> result;
    result.first = left.first && right.first && (abs(left.second - right.second) <= 1);
    result.second = 1 + max(left.second, right.second);

    return result;
}

bool isBalanced(CustomTree::TreeNode* root) {
    return maxDepth(root).first;
}

int main() {

    vector<string> nodes = {"3","9","20","null","null","15","7"};
    // vector<string> nodes = {"1","2","2","3","3","null","null","4","4"};
    // vector<string> nodes = {};
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    // printTree(node);
    cout << isBalanced(root) << "\n";

    return 0;
}