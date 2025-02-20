#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        int prefix_product = 1;
        int suffix_product = 1;
        for(int i = 0, j = n - 1; i < n; ++i, --j){
            answer[i] *= prefix_product;
            answer[j] *= suffix_product;
            prefix_product *= nums[i];
            suffix_product *= nums[j];
        }
        return answer;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        vector<int> left(n), right(n);
        left[0] = 1;
        right[n - 1] = 1;
        for(int i = 1; i < n; ++i){
            left[i] = left[i - 1] * nums[i - 1];
        }

        for(int i = n - 2; i >= 0; --i){
            right[i] = right[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; ++i){
            answer[i] = left[i] * right[i];
        }
        return answer;
    }
};