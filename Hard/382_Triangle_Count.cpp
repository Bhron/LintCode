class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        if (S.size() <= 2) {
            return 0;
        }

        sort(S.begin(), S.end());

        int counter = 0;
        for(int i = 0; i < S.size(); i++) {
            int start = 0, end = i - 1;
            while(start < end) {
                if(S[start] + S[end] > S[i]) {
                    counter += (end - start);
                    end --;
                } else {
                    start ++;
                }
            }
        }

        return counter;
    }
};
