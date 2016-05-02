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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || preorder.size() != inorder.size()) {
            return NULL;
        }

        return build_tree_helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode *build_tree_helper(const vector<int>& preorder, int preorder_start, int preorder_end, const vector<int>& inorder, int inorder_start, int inorder_end) {
        if (preorder_start > preorder_end) {
            return NULL;
        }

        int root_val = preorder[preorder_start];
        TreeNode* root = new TreeNode(root_val);

        int inorder_root_index;
        for (inorder_root_index = inorder_start; inorder_root_index <= inorder_end && inorder[inorder_root_index] != root_val; inorder_root_index++) {
            ;
        }

        root->left = build_tree_helper(preorder, preorder_start + 1, preorder_start + inorder_root_index - inorder_start, inorder, inorder_start, inorder_root_index - 1);
        root->right = build_tree_helper(preorder, preorder_start + inorder_root_index - inorder_start + 1, preorder_end, inorder, inorder_root_index + 1, inorder_end);

        return root;
    }
};
