class Solution {
public:
    /**
     * @param stk an integer stack
     * @return void
     */
    void stackSorting(stack<int>& stk) {
        stack<int> s;

        while (!stk.empty()) {
            if (s.empty() || s.top() >= stk.top()) {
                s.push(stk.top());
                stk.pop();
            } else {
                int val = stk.top();
                stk.pop();

                while (!s.empty() && val >= s.top()) {
                    stk.push(s.top());
                    s.pop();
                }
                s.push(val);
            }
        }

        while (!s.empty()) {
            stk.push(s.top());
            s.pop();
        }
    }
};
