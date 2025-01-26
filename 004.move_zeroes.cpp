#include <vector>
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 遍历两次，第一遍遍历记录0的个数并且将非零数填充至前j位
        if(!nums.size()) return;
        int j = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]){
                nums[j++] = nums[i];
            }
        }
        // 第二遍遍历则将第 j + 1 位到最后一位的数据赋值为零
        for(int i = j; i < nums.size(); ++i){
            nums[i] = 0;
        }
        return;
    }
    void moveZeroes(vector<int>& nums){
        // 参考快速排序，将非零数放在左边，零放在右边
        // 遍历一遍，每次找到非零数就交换位置
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] != 0) {
                std::swap(nums[left], nums[right]);
                left++;
            }
        }
    }

};
