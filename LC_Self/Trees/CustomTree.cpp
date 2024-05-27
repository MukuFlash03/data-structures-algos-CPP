#include "CustomTree.h"

using namespace std;

// void CustomTree::createTree(TreeNode* node, int i, vector<string>& arr) {
//     for (const auto& elem : arr) {
//         cout << elem << "\n";
//     }

//     if (node != nullptr) {
//         if (2 * i + 1 < arr.size()) {
//             if (arr[2 * i + 1] == "null")
//                 node->left = nullptr;
//             else
//                 node->left = new TreeNode(stoi(arr[2 * i + 1]));
//             createTree(node->left, 2 * i + 1, arr);
//         }

//         if (2 * i + 2 < arr.size()) {
//             if (arr[2 * i + 2] == "null")
//                 node->right = nullptr;
//             else
//                 node->right = new TreeNode(stoi(arr[2 * i + 2]));
//             createTree(node->right, 2 * i + 2, arr);
//         }
//     }
// }

void CustomTree::createTree(TreeNode* &node, int i, const vector<string>& arr) {
    if (i >= arr.size() || arr[i] == "null") {
        node = nullptr;
        return;
    }

    node = new TreeNode(stoi(arr[i]));

    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    createTree(node->left, leftIndex, arr);
    createTree(node->right, rightIndex, arr);
}

CustomTree::TreeNode* CustomTree::levelOrderCreateTree(vector<string>& arr) {
    if (arr.size() == 0)
        return nullptr;
    
    TreeNode *root = new TreeNode(stoi(arr[0]));
    createTree(root, 0, arr);

    return root;
}

vector<string> CustomTree::treeToArray(TreeNode* root) {
    vector<string> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }

    // Remove trailing "null" values to minimize array size
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    return result;
}


void CustomTree::printTree(TreeNode* root) { 
    if(root == nullptr) {
        // cout << "null\t";
        return;
    }
    cout << root->val << "\t";
    printTree(root->left);
    printTree(root->right);
}

CustomTree::TreeNode* CustomTree::findNode(TreeNode* root, int val) { 
    if (root == nullptr) 
        return nullptr;
    if (root->val == val) 
        return root;

    TreeNode* leftSearch = findNode(root->left, val);

    if (leftSearch != nullptr) 
        return leftSearch;

    return findNode(root->right, val);
}