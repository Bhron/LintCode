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
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (head == NULL) {
            return;
        }

        ListNode* mid = get_middle(head);
        ListNode* node = reverse(mid->next);
        mid->next = NULL;

        merge(head, node);
    }
private:
    ListNode *get_middle(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode *reverse(ListNode* head) {
        ListNode* prev = NULL;

        while (head != NULL) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }

    ListNode *merge(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);
        ListNode* node = &dummy;
        int index = 0;

        while (head1 != NULL && head2 != NULL) {
            if (index % 2 == 0) {
                node->next = head1;
                head1 = head1->next;
            } else {
                node->next = head2;
                head2 = head2->next;
            }
            node = node->next;
            index++;
        }

        if (head1 != NULL) {
            node->next = head1;
        }
        if (head2 != NULL) {
            node->next = head2;
        }

        return dummy.next;
    }
};
