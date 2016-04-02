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

// O(n)
class Solution {
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a complete binary tree, or false.
     */
    bool isComplete(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        vector<TreeNode*> nodes;
        nodes.push_back(root);

        for (int i = 0; i < nodes.size(); i++) {
            TreeNode* node = nodes[i];

            if (node != NULL) {
                nodes.push_back(node->left);
                nodes.push_back(node->right);
            }
        }

        while (nodes[nodes.size() - 1] == NULL) {
            nodes.pop_back();
        }

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == NULL) {
                return false;
            }
        }

        return true;
    }
};

// Divide & Conquer
class Solution {
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a complete binary tree, or false.
     */
    bool isComplete(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        ResultType result = helper(root);

        return result.is_complete;
    }
private:
    class ResultType {
    public:
        int depth;
        bool is_full;
        bool is_complete;

        ResultType(int depth, bool is_full, bool is_complete) {
            this->depth = depth;
            this->is_full = is_full;
            this->is_complete = is_complete;
        }
    };

    ResultType helper(TreeNode* root) {
        if (root == NULL) {
            return ResultType(0, true, true);
        }

        ResultType left = helper(root->left);
        ResultType right = helper(root->right);

        if (!left.is_complete) {
            return ResultType(-1, false, false);
        }

        if (left.depth == right.depth) {
            if (!left.is_full || !right.is_complete) {
                return ResultType(-1, false, false);
            }
            return ResultType(left.depth + 1, right.is_full, true);
        }

        if (left.depth == right.depth + 1) {
            if (!left.is_complete || !right.is_full) {
                return ResultType(-1, false, false);
            }
            return ResultType(left.depth + 1, false, true);
        }

        return ResultType(-1, false, false);
    }
};
