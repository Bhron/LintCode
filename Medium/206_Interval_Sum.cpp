/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<long long> prefixSum;
        
        long long sum = 0;
        for (int i = 0; i < A.size(); i++) {
            prefixSum.push_back(sum);
            sum += A[i];
        }
        
        vector<long long> sums;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i].start;
            int end = queries[i].end;
            sums.push_back(prefixSum[end] - prefixSum[start] + A[end]);
        }
        
        return sums;
    }
};
