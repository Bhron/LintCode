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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(0);

        while (head != NULL) {
            ListNode* node = &dummy;
            ListNode* next = head->next;
            while (node->next != NULL && node->next->val < head->val) {
                node = node->next;
            }
            head->next = node->next;
            node->next = head;
            head = next;
        }

        return dummy.next;
    }
};
