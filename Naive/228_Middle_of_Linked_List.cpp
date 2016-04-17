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
class Solution{
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode *middleNode(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

class Solution{
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode *middleNode(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next == NULL) {
                break;
            }
            fast = fast->next;

            slow = slow->next;
        }

        return slow;
    }
};
