/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(h) Time, h is the height of the tree
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) {
            return NULL;
        }

        TreeNode *successor = NULL;
        while (root != NULL && root != p) {
            if (p->val < root->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }

        if (root == NULL) {
            return NULL;
        }

        if (root->right == NULL) {
            return successor;
        }

        root = root->right;
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
};
