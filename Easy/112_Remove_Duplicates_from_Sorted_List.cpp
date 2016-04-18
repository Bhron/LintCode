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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* node = head;
        while (node->next != NULL) {
            if (node->val == node->next->val) {
                ListNode* tmp = node->next;
                node->next = node->next->next;
                delete tmp;
            } else {
                node = node->next;
            }
        }

        return head;
    }
};
