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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> values;

        if (root == NULL) {
            return values;
        }

        stack<TreeNode *> s;
        TreeNode *cur = root;

        while (!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();
            values.push_back(cur->val);
            cur = cur->right;
        }

        return values;
    }
};

// Recursion
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
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
        values.push_back(root->val);
        helper(root->right, values);
    }
};
