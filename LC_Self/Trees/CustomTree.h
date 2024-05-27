#ifndef CUSTOMTREE_H
#define CUSTOMTREE_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CustomTree {
    private:

    public:

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    // void createTree(TreeNode* node, int i, vector<string>& arr);
    void createTree(TreeNode* &node, int i, const vector<string>& arr);
    TreeNode* levelOrderCreateTree(vector<string>& arr);
    void printTree(TreeNode* root);
    CustomTree::TreeNode* findNode(TreeNode* root, int val);
    vector<string> treeToArray(TreeNode* root);

};

#endif
