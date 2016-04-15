/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        int n = get_length(head);
        cur = head;

        return sorted_list_to_BST_helper(n);
    }
private:
    ListNode* cur;

    int get_length(ListNode* head) {
        int length = 0;

        while (head != NULL) {
            length++;
            head = head->next;
        }

        return length;
    }

    TreeNode *sorted_list_to_BST_helper(int n) {
        if (n <= 0) {
            return NULL;
        }

        TreeNode* left = sorted_list_to_BST_helper(n / 2);
        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next;
        TreeNode* right = sorted_list_to_BST_helper(n - n / 2 - 1);

        root->left = left;
        root->right = right;

        return root;
    }
};
