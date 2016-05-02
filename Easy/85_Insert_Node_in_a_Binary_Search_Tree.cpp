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

// Recursion
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (node == NULL) {
            return root;
        }

        root = insert_node_helper(root, node);

        return root;
    }
private:
    TreeNode* insert_node_helper(TreeNode* root, TreeNode* node) {
        if (root == NULL) {
            return node;
        }

        if (node->val < root->val) {
            root->left = insert_node_helper(root->left, node);
        } else {
            root->right = insert_node_helper(root->right, node);
        }
        return root;
    }
};

// Non-Recursion
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (node == NULL) {
            return root;
        }
        if (root == NULL) {
            return node;
        }

        TreeNode* prev = NULL;
        TreeNode* cur = root;
        while (cur != NULL) {
            prev = cur;
            if (node->val < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        if (node->val < prev->val) {
            prev->left = node;
        } else {
            prev->right = node;
        }

        return root;
    }
};
