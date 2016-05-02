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

// Non-Recursion
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> values;

        if (root == NULL) {
            return values;
        }

        stack<TreeNode *> s;
        s.push(root);
        TreeNode *prev = NULL;
        TreeNode *cur = root;

        while (!s.empty()) {
            cur = s.top();

            if (prev == NULL || prev->left == cur || prev->right == cur) {
                if (cur->left != NULL) {
                    s.push(cur->left);
                } else if (cur->right != NULL) {
                    s.push(cur->right);
                }
            } else if (cur->left == prev) {
                if (cur->right != NULL) {
                    s.push(cur->right);
                }
            } else {
                values.push_back(cur->val);
                s.pop();
            }

            prev = cur;
        }

        return values;
    }
};

// Recursion
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> values;

        helper(root, values);

        return values;
    }
private:
    void helper(TreeNode* root, vector<int>& values) {
        if (root == NULL) {
            return;
        }

        helper(root->left, values);
        helper(root->right, values);
        values.push_back(root->val);
    }
};
