class Solution {
public:
    /**
     * @param arrays k sorted integer arrays
     * @return a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
        if (arrays.empty()) {
            return vector<int>();
        }

        vector<int> result;

        // Min Heap
        priority_queue<Element, vector<Element>, Compare> pq;
        for (int i = 0; i < arrays.size(); i++) {
            if (arrays[i].size() > 0) {
                pq.push(Element(i, 0, arrays[i][0]));
            }
        }

        while (!pq.empty()) {
            Element elem = pq.top();
            pq.pop();

            result.push_back(elem.val);

            if (elem.j + 1 < arrays[elem.i].size()) {
                elem.j++;
                elem.val = arrays[elem.i][elem.j];
                pq.push(elem);
            }
        }

        return result;
    }
private:
    class Element {
    public:
        int i;
        int j;
        int val;

        Element(int i, int j, int val) {
            this->i = i;
            this->j = j;
            this->val = val;
        }
    };

    // Min Heap
    class Compare {
    public:
        bool operator() (const Element& left, const Element& right) {
            return left.val > right.val;
        }
    };
};

class Solution {
public:
    /**
     * @param arrays k sorted integer arrays
     * @return a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
        if (arrays.empty()) {
            return vector<int>();
        }

        return helper(arrays, 0, arrays.size() - 1);
    }
private:
    vector<int> helper(vector<vector<int>>& arrays, int start, int end) {
        if (start >= end) {
            return arrays[start];
        }

        int mid = start + (end - start) / 2;

        vector<int> left = helper(arrays, start, mid);
        vector<int> right = helper(arrays, mid + 1, end);

        return merge(left, right);
    }

    vector<int> merge(vector<int>& array1, vector<int>& array2) {
        vector<int> array;

        int i = 0, j = 0;
        while (i < array1.size() && j < array2.size()) {
            if (array1[i] < array2[j]) {
                array.push_back(array1[i++]);
            } else {
                array.push_back(array2[j++]);
            }
        }

        while (i < array1.size()) {
            array.push_back(array1[i++]);
        }
        while (j < array2.size()) {
            array.push_back(array2[j++]);
        }

        return array;
    }
};
