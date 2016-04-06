class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        stack<int> s;

        int max_area = INT_MIN;
        for (int i = 0; i <= heights.size(); i++) {
            int cur_height = i < heights.size() ? heights[i] : -1;
            while (!s.empty() && cur_height <= heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                max_area = max(max_area, h * w);
            }
            s.push(i);
        }

        return max_area;
    }
};
