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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || k <= 1) {
            return head;
        }

        int length = get_length(head);
        int n = length / k;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre_tail = &dummy;

        while (n > 0) {
            ListNode* cur_tail = pre_tail->next;
            ListNode* prev = cur_tail;
            ListNode* node = prev->next;
            for (int i = 0; i < k - 1; i++) {
                ListNode* tmp = node->next;
                node->next = prev;
                prev = node;
                node = tmp;
            }
            pre_tail->next = prev;
            cur_tail->next = node;

            pre_tail = cur_tail;
            n--;
        }

        return dummy.next;
    }
private:
    int get_length(ListNode *head) {
        int length = 0;

        while (head != NULL) {
            length++;
            head = head->next;
        }

        return length;
    }
};
