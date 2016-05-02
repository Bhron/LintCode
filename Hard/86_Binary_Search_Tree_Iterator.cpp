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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */

// O(h) Space, h is the height of the tree
class Solution {
private:
    TreeNode* cur;
    stack<TreeNode *> s;
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        while (!s.empty()) {
            s.pop();
        }

        cur = root;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return cur != NULL || !s.empty();
    }

    //@return: return next node
    TreeNode* next() {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }

        TreeNode* node = s.top();
        s.pop();

        cur = node->right;

        return node;
    }
};
