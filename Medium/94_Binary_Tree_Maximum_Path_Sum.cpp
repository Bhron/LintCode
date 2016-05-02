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
    int maxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        ResultType result = max_path_sum_helper(root);

        return result.max_path;
    }
private:
    class ResultType {
    public:
        // maxPath: max path from any node to any node, has at least one node
        int max_path;
        // singlePath: max path from root to any node below, can has zero node
        int single_path;

        ResultType(int max_path, int single_path) {
            this->max_path = max_path;
            this->single_path = single_path;
        }
    };

    ResultType max_path_sum_helper(TreeNode *root) {
        if (root == NULL) {
            return ResultType(INT_MIN, 0);
        }

        // Divide
        ResultType left = max_path_sum_helper(root->left);
        ResultType right = max_path_sum_helper(root->right);

        // Conquer
        int single_path = max(max(left.single_path, right.single_path) + root->val, 0);

        int max_path = max(left.max_path, right.max_path);
        max_path = max(left.single_path + right.single_path + root->val, max_path);

        return ResultType(max_path, single_path);
    }
};
