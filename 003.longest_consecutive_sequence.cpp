#include <vector>
#include <unordered_set>
using std::vector;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 由于要求时间复杂度O(N)，则不应该在此处引入std::sort，因为std::sort的时间复杂度为O(NlogN)
        std::unordered_set<int> u_set(nums.begin(), nums.end());
        int longest_consecutive = 0;
        // 遍历去重数组中的每个数字 num
        for(int num : u_set) {
            // 判断 num 是否是一个序列的起点
            // 如果 num-1 不在集合中，说明 num 是一个新序列的起点
            // 如果 num-1 在集合中，说明 num 不是序列的起点，已经被计算过
            
            if(u_set.find(num - 1) == u_set.end()) {
                // 如果是序列的起点，开始扩展序列
                int current_num = num;  // 当前数字
                int current_streak = 1; // 当前序列长度从 1 开始（至少包含 num 自己）
                
                // 循环查找连续的数字，即 num+1, num+2, ... 是否在集合中
                while(u_set.find(current_num + 1) != u_set.end()) {
                    ++current_num;      // 序列扩展到下一个数字
                    ++current_streak;   // 序列长度增加
                }

                // 更新最长序列长度
                longest_consecutive = std::max(longest_consecutive, current_streak);
            }
        }
        return longest_consecutive;
    }
};