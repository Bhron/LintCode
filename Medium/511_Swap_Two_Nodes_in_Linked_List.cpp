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
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        if (head == NULL) {
            return NULL;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev1 = NULL;
        ListNode* prev2 = NULL;
        ListNode* node = &dummy;

        while (node->next != NULL) {
            if (node->next->val == v1) {
                prev1 = node;
            } else if (node->next->val == v2) {
                prev2 = node;
            }
            node = node->next;
        }

        if (prev1 == NULL || prev2 == NULL) {
            return head;
        }

        ListNode* node1 = prev1->next;
        ListNode* node2 = prev2->next;
        ListNode* tmp;

        if (node1->next == node2) {
            tmp = node2->next;
            node2->next = node1;
            node1->next = tmp;

            prev1->next = node2;
        } else if (node2->next == node1) {
            tmp = node1->next;
            node1->next = node2;
            node2->next = tmp;

            prev2->next = node1;
        } else {
            tmp = node1->next;
            node1->next = node2->next;
            node2->next = tmp;

            prev1->next = node2;
            prev2->next = node1;
        }

        return dummy.next;
    }
};
