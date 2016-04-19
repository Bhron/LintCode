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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode dummy(0);
        ListNode* node = &dummy;

        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = 0;

            sum += carry;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            node->next = new ListNode(sum % 10);
            node = node->next;

            carry = sum / 10;
        }

        return reverse(dummy.next);
    }
private:
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
};
