/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k <= 0) {
            return head;
        }

        int length = 0;
        ListNode* node = head;
        ListNode* tail = NULL;
        while (node != NULL) {
            length++;
            tail = node;
            node = node->next;
        }

        k = k % length;
        if (k == 0) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        node = &dummy;
        for (int i = 0; i < length - k; i++) {
            node = node->next;
        }
        tail->next = dummy.next;
        dummy.next = node->next;
        node->next = NULL;

        return dummy.next;
    }
};
