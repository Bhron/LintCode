/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        return min_depth_helper(root);
    }
private:
    int min_depth_helper(TreeNode* root) {
        if (root == NULL) {
            return INT_MAX;
        }

        if (root->left == NULL && root->right == NULL) {
            return 1;
        }

        return min(min_depth_helper(root->left), min_depth_helper(root->right)) + 1;
    }
};
