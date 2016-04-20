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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* mid = get_middle(head);
        mid->next = reverse(mid->next);

        ListNode* node = mid->next;
        while (head != NULL && node != NULL && head->val == node->val) {
            head = head->next;
            node = node->next;
        }

        return node == NULL;
    }
private:
    ListNode* get_middle(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
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
