#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int global_min = std::numeric_limits<int>::max();
        MinDepthTree(root, 1, global_min);
        return global_min;
    }

    void MinDepthTree(TreeNode* node, int local_min, int& global_min) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL && global_min > local_min) {
            global_min = local_min;
        }
        MinDepthTree(node->left, local_min + 1, global_min);
        MinDepthTree(node->right, local_min + 1, global_min);
    }
};