// O(n) - Time & Space
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
     * @return: head node
     */
    ListNode *removeDuplicates(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;

        hash.clear();
        ListNode* node = &dummy;
        while (node->next != NULL) {
            if (hash.find(node->next->val) != hash.end()) {
                node->next = node->next->next;
            } else {
                hash.insert(node->next->val);
                node = node->next;
            }
        }

        return dummy.next;
    }
private:
    unordered_set<int> hash;
};

// Challenge - O(nlogn) Time, O(1) Space.  Won't pass the test, because the result requires keeping the order of nodes.
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *removeDuplicates(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        int len = get_length(head);

        ListNode dummy(0);
        dummy.next = merge_sort(head, len);

        ListNode* node = dummy.next;
        while (node->next != NULL) {
            if (node->next->val == node->val) {
                node->next = node->next->next;
            } else {
                node = node->next;
            }
        }

        return dummy.next;
    }
private:
    int get_length(ListNode *head) {
        int len = 0;

        while (head != NULL) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode *merge_sort(ListNode* head, int n) {
        if (n <= 1) {
            return head;
        }

        ListNode* mid = head;
        for (int i = 0; i < n / 2 - 1; i++) {
            mid = mid->next;
        }

        ListNode* tmp = mid->next;
        mid->next = NULL;
        mid = tmp;

        ListNode* left = merge_sort(head, n / 2);
        ListNode* right = merge_sort(mid, n - n / 2);

        return merge(left, right);
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                node->next = head1;
                head1 = head1->next;
            } else {
                node->next = head2;
                head2 = head2->next;
            }
            node = node->next;
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
