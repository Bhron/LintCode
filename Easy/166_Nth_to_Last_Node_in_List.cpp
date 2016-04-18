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
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        if (head == NULL || n <= 0) {
            return head;
        }

        ListNode* node1 = head;
        for (int i = 0; i < n; i++) {
            if (node1 == NULL) {
                return NULL;
            }
            node1 = node1->next;
        }

        ListNode* node2 = head;
        while (node1 != NULL) {
            node1 = node1->next;
            node2 = node2->next;
        }

        return node2;
    }
};
