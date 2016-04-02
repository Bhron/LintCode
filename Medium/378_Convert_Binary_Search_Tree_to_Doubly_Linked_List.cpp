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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        stack<TreeNode*> s;
        TreeNode* node = root;
        DoublyListNode* prev = NULL;
        DoublyListNode* head;

        while (!s.empty() || node != NULL) {
            while (node != NULL) {
                s.push(node);
                node = node->left;
            }

            TreeNode* cur = s.top();
            s.pop();

            DoublyListNode* new_node = new DoublyListNode(cur->val);

            if (prev == NULL) {
                head = new_node;
            } else {
                prev->next = new_node;
                new_node->prev = prev;
            }
            prev = new_node;

            node = cur->right;
        }

        return head;
    }
};
