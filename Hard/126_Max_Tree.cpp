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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        stack<TreeNode*> s;

        for (int i = 0; i <= A.size(); i++) {
            TreeNode* cur = i < A.size() ? new TreeNode(A[i]) : new TreeNode(INT_MAX);

            while (!s.empty() && cur->val > (s.top())->val) {
                TreeNode* node = s.top();
                s.pop();

                if (s.empty()) {
                    cur->left = node;
                } else {
                    TreeNode* left = s.top();

                    if (left->val > cur->val) {
                        cur->left = node;
                    } else {
                        left->right = node;
                    }
                }
            }

            s.push(cur);
        }

        return (s.top())->left;
    }
};
