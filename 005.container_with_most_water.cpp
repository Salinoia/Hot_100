#include <vector>
class Solution {
public:
    void updateMax(const std::vector<int>& height, int left, int right, int& maxArea){
        int width = right - left;
        int length = std::min(height[left], height[right]);
        maxArea = std::max(maxArea, width * length);
    }
    int maxArea(std::vector<int>& height) {
        // 可以近似看成一个二维的平面矩阵面积求最值
        int right = height.size() - 1;
        int left = 0;
        int maxArea = 0;
        while(left < right){
            // int width = right - left;
            // int length = std::min(height[left], height[right]);
            // maxArea = std::max(maxArea, width*length);
            updateMax(height, left, right, maxArea);
            if(height[left] < height[right]){
                ++left;
            }
            else{
                --right;
            }
        }
        return maxArea;
    }
};