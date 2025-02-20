#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 三种方法：扩充，翻转，替换

        // vector<int> newArray(nums.size(), 0);
        // for(int i = 0; i < nums.size(); ++i){
        //     newArray[(i + k) % nums.size()] = nums[i]; 
        // }
        // nums.assign(newArray.begin(), newArray.end());

        int n = nums.size();
        if(k > n) k %= n;
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
        return;
    }
};