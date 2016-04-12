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
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) {
            return NULL;
        }

        ListNode dummy_left(0);
        ListNode dummy_right(0);

        ListNode* left = &dummy_left;
        ListNode* right = &dummy_right;
        ListNode* node = head;
        while (node != NULL) {
            if (node->val < x) {
                left->next = node;
                left = node;
            } else {
                right->next = node;
                right = node;
            }
            node = node->next;
        }

        right->next = NULL;
        left->next = dummy_right.next;

        return dummy_left.next;
    }
};
