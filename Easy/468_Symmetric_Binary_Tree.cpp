// Recursion, O(n) Time, O(n) Space (Stack call)
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
     * @param root, the root of binary tree.
     * @return true if it is a mirror of itself, or false.
     */
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return is_symmetric_helper(root->left, root->right);
    }
private:
    bool is_symmetric_helper(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }

        if (root1 == NULL || root2 == NULL) {
            return false;
        }

        if (root1->val != root2->val) {
            return false;
        }

        return is_symmetric_helper(root1->left, root2->right) && is_symmetric_helper(root1->right, root2->left);
    }
};

// Iterative, O(n) Time, O(n) Space
class Solution {
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a mirror of itself, or false.
     */
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while (!q.empty()) {
            TreeNode* root1 = q.front();
            q.pop();

            TreeNode* root2 = q.front();
            q.pop();

            if (root1 == NULL && root2 == NULL) {
                continue;
            }
            if (root1 == NULL || root2 == NULL || root1->val != root2->val) {
                return false;
            }

            q.push(root1->left);
            q.push(root2->right);

            q.push(root1->right);
            q.push(root2->left);
        }

        return true;
    }
};
