#include <vector>
#include <stack>
using std::stack;
using std::vector;
class Solution {
public:
    // 单调栈
    int trap(vector<int>& height) {
        std::stack<int> st; // indices stack
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            // While current bar is taller than (or equal to) the top of stack,
            // we have found a right boundary for the bar at the stack top.
            while (!st.empty() && height[i] >= height[st.top()]) {
                int bottom = st.top();
                st.pop();
                // If stack is empty after popping, no left boundary exists
                if (st.empty()) {
                    break;
                }
                int h = std::min(height[i], height[st.top()]) - height[bottom];
                int w = i - st.top() - 1;
                sum += h * w;
            }
            st.push(i);
        }
        return sum;
    }
};
    // 动态规划
    class Solution {
    public:
        int trap(vector<int>& height) {
            if (height.size() <= 2) return 0;
            vector<int> maxLeft(height.size(), 0);
            vector<int> maxRight(height.size(), 0);
            int size = maxRight.size();

            // 记录每个柱子左边柱子最大高度
            maxLeft[0] = height[0];
            for (int i = 1; i < size; i++) {
                maxLeft[i] = std::max(height[i], maxLeft[i - 1]);
            }
            // 记录每个柱子右边柱子最大高度
            maxRight[size - 1] = height[size - 1];
            for (int i = size - 2; i >= 0; i--) {
                maxRight[i] = std::max(height[i], maxRight[i + 1]);
            }
            // 求和
            int sum = 0;
            for (int i = 0; i < size; i++) {
                int count = std::min(maxLeft[i], maxRight[i]) - height[i];
                if (count > 0) sum += count;
            }
            return sum;
        }
    };

    // 双指针
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMaxVal = 0, rightMaxVal = 0;
        int res = 0;
        while (left < right){
            leftMaxVal = std::max(leftMaxVal, height[left]);
            rightMaxVal = std::max(rightMaxVal, height[right]);
            // 如果 `height[left]<height[right]`，那么对于下标 `left` 而言，其右侧一定存在一个高度至少是 `height[right]` 的柱子，
            // 所以此时能否接到水、接多少水，**只由 `left` 侧的最高柱子 `leftMax` 决定**。
            // 因此可以放心地计算 `left` 位置的盛水量，并让 `left++` 向右移动。

            // 反之如果 `height[left]≥height[right]`，则对下标 `right` 而言，其左侧一定存在一个高度至少是 `height[left]` 的柱子，
            // 所以能否接到水、接多少水，只由 `right` 侧的最高柱子 `rightMax` 决定。
            // 此时可计算 `right` 位置的盛水量，再让 `right--` 向左移动。

            if(height[left] < height[right]){
                res += leftMaxVal - height[left];
                left++;
            }
            else{
                res += rightMaxVal - height[right];
                right--;
            }
        }
        return res;
    }