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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (n <= 0) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode *node = head;
        for (int i = 0; i < n; i++) {
            if (node == NULL) {
                return NULL;
            }
            node = node->next;
        }

        ListNode *prev = &dummy;
        while (node != NULL) {
            prev = prev->next;
            node = node->next;
        }
        ListNode *tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;

        return dummy.next;
    }
};
