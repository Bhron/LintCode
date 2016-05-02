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

// Traverse
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        if (!isValidBST(root->left)) {
            return false;
        }

        if (last != NULL && root->val <= last->val) {
            return false;
        }
        last = root;

        if (!isValidBST(root->right)) {
            return false;
        }

        return true;
    }
private:
    TreeNode *last = NULL;
};

// Divide & Conquer
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        ResultType result = is_valid_helper(root);

        return result.is_valid == true;
    }
private:
    class ResultType {
    public:
        bool is_valid;
        int min_val;
        int max_val;

        ResultType(bool is_valid = true, int min_val = INT_MAX, int max_val = INT_MIN) {
            this->is_valid = is_valid;
            this->min_val = min_val;
            this->max_val = max_val;
        }
    };

    ResultType is_valid_helper(TreeNode *root) {
        if (root == NULL) {
            return ResultType();
        }

        // Divide
        ResultType left = is_valid_helper(root->left);
        ResultType right = is_valid_helper(root->right);

        // Conquer
        if (!left.is_valid || !right.is_valid ||
            root->left != NULL && left.max_val >= root->val ||
            root->right != NULL && root->val >= right.min_val) {
            return ResultType(false, 0, 0);
        }

        return ResultType(true,
                          min(left.min_val, root->val),
                          max(root->val, right.max_val));
    }
};
