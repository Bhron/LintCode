class Queue {
public:
    Queue() {
        dummy = new ListNode(0);
        tail = NULL;
    }

    void enqueue(int item) {
        ListNode* new_node = new ListNode(item);

        if (tail == NULL) {
            dummy->next = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = tail->next;
        }
    }

    int dequeue() {
        ListNode* node = dummy->next;
        dummy->next = node->next;
        if (node == tail) {
            tail = NULL;
        }

        int val = node->val;
        delete node;

        return val;
    }
private:
    class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
    };

    ListNode* dummy;
    ListNode* tail;
};
