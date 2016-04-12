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
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* node = &dummy;
        while (node->next != NULL && node->next->next != NULL) {
            if (node->next->val == node->next->next->val) {
                int val = node->next->val;
                while (node->next != NULL && node->next->val == val) {
                    ListNode* tmp = node->next;
                    node->next = node->next->next;
                    delete tmp;
                }
            } else {
                node = node->next;
            }
        }

        return dummy.next;
    }
};
