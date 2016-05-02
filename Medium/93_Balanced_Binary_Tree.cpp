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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return helper(root) != -1;
    }
private:
    int helper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int left = helper(root->left);
        int right = helper(root->right);

        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        ResultType result = is_balanced_helper(root);

        return result.is_balanced;
    }
private:
    class ResultType {
    public:
        bool is_balanced;
        int depth;

        ResultType(bool is_balanced = true, int depth = 0) {
            this->is_balanced = is_balanced;
            this->depth = depth;
        }
    };

    ResultType is_balanced_helper(TreeNode *root) {
        if (root == NULL) {
            return ResultType();
        }

        ResultType left = is_balanced_helper(root->left);
        ResultType right = is_balanced_helper(root->right);

        if (!left.is_balanced || !right.is_balanced || abs(left.depth - right.depth) > 1) {
            return ResultType(false, 0);
        }
        return ResultType(true, max(left.depth, right.depth) + 1);
    }
};
