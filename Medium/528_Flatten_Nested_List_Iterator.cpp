/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push(Pair(nestedList, 0));
    }

    // @return {int} the next element in the iteration
    int next() {
        Pair& cur = s.top();

        int val = cur.list[cur.index].getInteger();
        cur.index++;

        return val;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        while (!s.empty()) {
            Pair& cur = s.top();

            if (cur.index == cur.list.size()) {
                s.pop();

                if (!s.empty()) {
                    Pair& prev = s.top();
                    prev.index++;
                }
            } else if (cur.list[cur.index].isInteger() == false) {
                s.push(Pair(cur.list[cur.index].getList(), 0));
            } else {
                return true;
            }
        }

        return false;
    }
private:
    class Pair {
    public:
        const vector<NestedInteger> &list;
        int index;

        Pair(const vector<NestedInteger>& nested_list, int index) : list(nested_list), index(index) { }
    };

    stack<Pair> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
