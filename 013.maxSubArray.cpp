#include <vector>
#include <climits>
using std::vector;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0;
        for(int num : nums){
            sum += num;
            if(num > max) max = sum;
            if(max <= 0) sum = 0;
        }
        return max;
    }
    int maxSubArray(vector<int>& nums){
        // dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            res = std::max(dp[i], res);
        }
        return res;
    }
};