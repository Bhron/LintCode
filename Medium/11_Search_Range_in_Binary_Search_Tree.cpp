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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> keys;

        if (root == NULL) {
            return keys;
        }

        search_range_helper(keys, root, k1, k2);

        return keys;
    }
private:
    void search_range_helper(vector<int>& keys, TreeNode *root, int k1, int k2) {
        if (root == NULL) {
            return;
        }

        if (k1 < root->val) {
            search_range_helper(keys, root->left, k1, k2);
        }

        if (k1 <= root->val && root->val <= k2) {
            keys.push_back(root->val);
        }

        if (root->val < k2) {
            search_range_helper(keys, root->right, k1, k2);
        }
    }
};
