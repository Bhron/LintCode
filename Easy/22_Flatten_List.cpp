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

// Recursion
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> flattenedList;

        helper(nestedList, flattenedList);

        return flattenedList;
    }
private:
    void helper(const vector<NestedInteger> &nestedList, vector<int> &flattenedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                flattenedList.push_back(nestedList[i].getInteger());
            } else {
                helper(nestedList[i].getList(), flattenedList);
            }
        }
    }
};

// Non-Recursion
class Pair {
public:
    const vector<NestedInteger>& list;
    int pos;

    Pair(const vector<NestedInteger> &list, int pos): list(list), pos(pos) { }
};

class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> flattenedList;

        stack<Pair> stk;
        stk.push(Pair(nestedList, 0));

        while (!stk.empty()) {
            Pair p = stk.top();
            stk.pop();

            const vector<NestedInteger>& list = p.list;
            for (int i = p.pos; i < list.size(); i++) {
                if (list[i].isInteger()) {
                    flattenedList.push_back(list[i].getInteger());
                } else {
                    stk.push(Pair(list, i + 1));
                    stk.push(Pair(list[i].getList(), 0));
                    break;
                }
            }
        }

        return flattenedList;
    }
};
