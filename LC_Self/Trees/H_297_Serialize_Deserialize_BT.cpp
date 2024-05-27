/*

Construct BT: https://www.linkedin.com/pulse/create-binary-tree-from-array-suhasis-saha/

Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
Solution(s):

YouTube
NC - https://www.youtube.com/watch?v=Hr5cWUld4vU
*/


/*

A. Recursive Approach



*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "CustomTree.h"
#include<queue>
#include<sstream>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

public:

    string serialize(CustomTree::TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    CustomTree::TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(CustomTree::TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    CustomTree::TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        CustomTree::TreeNode* root = new CustomTree::TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};


int main() {

    vector<string> nodes = {"1", "2", "3", "null", "null", "4", "5"};
    // vector<string> nodes = {""};
    
    // Tree creation function fails for this input. 
    // vector<string> nodes = {"1", "2", "3", "null", "null", "4", "5", "6", "7"};
    
    CustomTree ctree;
    CustomTree::TreeNode* root = ctree.levelOrderCreateTree(nodes);
    ctree.printTree(root);
    
    Codec ser, deser;
    string levels = ser.serialize(root);
    for(auto level : levels) {
        cout << level << "\n";
    }
    CustomTree::TreeNode* deRoot = deser.deserialize(levels);
    ctree.printTree(deRoot);

    return 0;
}