class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int N = nums.size();
        
        unsigned int sum = 0;
        for (int i = 0; i <= N; i++) {
            sum += i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
        }
        
        return sum;
    }
};
