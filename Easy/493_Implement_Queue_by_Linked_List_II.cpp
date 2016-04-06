class Dequeue {
public:
    Dequeue() {
        dummy = new ListNode(0);
        tail = NULL;
    }

    void push_front(int item) {
        ListNode* new_node = new ListNode(item);
        new_node->prev = dummy;
        new_node->next = dummy->next;

        if (tail == NULL) {
            tail = new_node;
        }

        if (dummy->next != NULL) {
            dummy->next->prev = new_node;
        }

        dummy->next = new_node;
    }

    void push_back(int item) {
        ListNode* new_node = new ListNode(item);

        if (tail == NULL) {
            new_node->prev = dummy;
            dummy->next = new_node;

            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = tail->next;
        }
    }

    int pop_front() {
        ListNode* node = dummy->next;

        ListNode* next = node->next;

        dummy->next = next;
        if (next != NULL) {
            next->prev = dummy;
        }

        if (node == tail) {
            tail = NULL;
        }

        int val = node->val;
        delete node;

        return val;
    }

    int pop_back() {
        ListNode* node = tail;

        ListNode* prev = tail->prev;
        prev->next = NULL;

        if (prev == dummy) {
            tail = NULL;
        } else {
            tail = prev;
        }

        int val = node->val;
        delete node;

        return val;
    }
private:
    class ListNode {
    public:
        int val;
        ListNode* prev;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    ListNode* dummy;
    ListNode* tail;
};
