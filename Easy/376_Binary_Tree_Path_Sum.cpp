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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        vector<vector<int>> paths;

        if (root == NULL) {
            return paths;
        }

        vector<int> cur_path;

        binary_tree_path_sum_helper(root, target, paths, cur_path);

        return paths;
    }
private:
    void binary_tree_path_sum_helper(TreeNode* root, int target, vector<vector<int>>& paths, vector<int>& cur_path) {
        if (root == NULL) {
            return;
        }

        cur_path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (root->val == target) {
                paths.push_back(vector<int>(cur_path));
            }
        } else {
            binary_tree_path_sum_helper(root->left, target - root->val, paths, cur_path);
            binary_tree_path_sum_helper(root->right, target - root->val, paths, cur_path);
        }

        cur_path.pop_back();
    }
};
