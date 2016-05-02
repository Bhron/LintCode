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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || inorder.size() != postorder.size()) {
            return NULL;
        }

        return build_tree_helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode *build_tree_helper(const vector<int>& inorder, int inorder_start, int inorder_end, const vector<int>& postorder, int postorder_start, int postorder_end) {
        if (inorder_start > inorder_end) {
            return NULL;
        }

        int root_val = postorder[postorder_end];
        TreeNode* root = new TreeNode(root_val);

        int inorder_root_index;
        for (inorder_root_index = inorder_start; inorder_root_index < inorder_end && inorder[inorder_root_index] != root_val; inorder_root_index++) {
            ;
        }

        root->left = build_tree_helper(inorder, inorder_start, inorder_root_index - 1, postorder, postorder_start, postorder_start + inorder_root_index - inorder_start - 1);
        root->right = build_tree_helper(inorder, inorder_root_index + 1, inorder_end, postorder, postorder_start + inorder_root_index - inorder_start, postorder_end - 1);

        return root;
    }
};
