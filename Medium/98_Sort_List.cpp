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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = get_middle(head);

        ListNode* right = sortList(mid->next);
        mid->next = NULL;
        ListNode* left = sortList(head);

        return merge(left, right);
    }
private:
    ListNode *get_middle(ListNode *head) {
        if (head == NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode *merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                node->next = left;
                left = left->next;
            } else {
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }

        if (left != NULL) {
            node->next = left;
        }
        if (right != NULL) {
            node->next = right;
        }

        return dummy.next;
    }
};
