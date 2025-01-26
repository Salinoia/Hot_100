#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            // 由于数组已经排序，若当前数字大于 0，则不可能找到三个和为零的三元组
            if (nums[i] > 0) {
                return res;
            }
            // 跳过重复的元素，避免重复的三元组
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;  // 总和小于 0，左指针右移，增大总和
                } 
                else if (sum > 0) {
                    right--; // 总和大于 0，右指针左移，减小总和
                } 
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // 跳过重复的元素，确保没有重复的三元组
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    // 移动指针到下一个不同的元素
                    left++;
                    right--;
                }
            }
        }
        
        return res;
    }
};
