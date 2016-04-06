class Stack {
public:
    Stack() {
        dummy = new ListNode(0);
        size = 0;
    }

    ~Stack() {
        ListNode* node = dummy->next;
        while (node != NULL) {
            ListNode* tmp = node;
            node = node->next;
            delete tmp;
        }
        delete dummy;
    }

    // Push a new item into the stack
    void push(int x) {
        ListNode* new_node = new ListNode(x);
        new_node->next = dummy->next;
        dummy->next = new_node;
        size++;
    }

    // Pop the top of the stack
    void pop() {
        ListNode* tmp = dummy->next;
        dummy->next = tmp->next;
        size--;
        delete tmp;
    }

    // Return the top of the stack
    int top() {
        return dummy->next->val;
    }

    // Check the stack is empty or not.
    bool isEmpty() {
        return size == 0;
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
    int size;
};
