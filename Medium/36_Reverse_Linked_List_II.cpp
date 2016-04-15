/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || m <= 0 || m >= n) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* node = &dummy;
        for (int i = 0; i < m - 1; i++) {
            if (node->next == NULL) {
                return NULL;
            }
            node = node->next;
        }

        ListNode* m_node = node->next;
        if (m_node == NULL) {
            return NULL;
        }
        ListNode* pre_m_node = node;

        ListNode* prev = m_node;
        node = m_node->next;
        for (int i = m; i < n; i++) {
            if (node == NULL) {
                return NULL;
            }
            ListNode* tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        pre_m_node->next = prev;
        m_node->next = node;

        return dummy.next;
    }
};
