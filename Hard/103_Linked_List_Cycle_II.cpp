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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != slow) {
            if (fast == NULL || fast->next == NULL) {
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        
        while (head != slow->next) {
            head = head->next;
            slow = slow->next;
        }
        
        return head;
    }
};
