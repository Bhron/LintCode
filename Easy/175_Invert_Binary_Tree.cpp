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

// Recursion, Up-Bottom
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
};

// Recursion, Bottom-Up
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        helper(root);
    }

private:
    TreeNode* helper(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* invertedLeft = helper(root->left);
        TreeNode* invertedRight = helper(root->right);

        root->left = invertedRight;
        root->right = invertedLeft;

        return root;
    }
};

// Non-Recursion
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }
};
