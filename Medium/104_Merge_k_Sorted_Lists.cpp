// Divide & Conquer - O(nlogn) Time, O(1) Space or O((logk)^2) Space (count recursion call stack space)
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return NULL;
        }

        return merge_k_lists_helper(lists, 0, lists.size() - 1);
    }
private:
    ListNode *merge_k_lists_helper(vector<ListNode *>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* left = merge_k_lists_helper(lists, start, mid);
        ListNode* right = merge_k_lists_helper(lists, mid + 1, end);

        return merge_two_lists(left, right);
    }

    ListNode *merge_two_lists(ListNode* head1, ListNode* head2) {
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


// Priority Queue - O(nlogn) Time, O(k) Space
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return NULL;
        }

        // Min Heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = node;

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
private:
    // Min Heap
    class Compare {
    public:
        bool operator() (const ListNode* left, const ListNode* right) {
            return left->val > right->val;
        }
    };
};
