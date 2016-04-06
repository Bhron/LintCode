class Stack {
public:
    Stack() {

    }

    ~Stack() {
        while (!q1.empty()) {
            q1.pop();
        }
        while (!q2.empty()) {
            q2.pop();
        }
    }

    // Push a new item into the stack
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        } else {
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    // Pop the top of the stack
    void pop() {
        if (!q1.empty()) {
            q1.pop();
        } else {
            q2.pop();
        }
    }

    // Return the top of the stack
    int top() {
        if (!q1.empty()) {
            return q1.front();
        } else {
            return q2.front();
        }
    }

    // Check the stack is empty or not.
    bool isEmpty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            int elem = q.front();
            q.pop();
            q.push(elem);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};
