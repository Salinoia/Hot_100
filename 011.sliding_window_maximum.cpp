#include <vector>
#include <deque>

using std::vector;
using std::deque;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue mq;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(i >= k){
                mq.pop(nums[i-k]);
            }
            // 先放入前k个数
            mq.push(nums[i]);
            if(i >= k - 1){
                res.push_back(mq.getMaxVal());
            }
        }
        return res;
    }
private:
    // 单调队列，维护每个窗口的最大值
    class MonotonicQueue{
    public:
        void pop(int val){
            if(!que.empty() && val == que.front()){
                que.pop_front();
            }
        }
        void push(int val){
            while(!que.empty() && val > que.back()){
                que.pop_back();
            }
            que.push_back(val);
        }
        int getMaxVal() const{
            return que.front();
        }
    private:
        deque<int> que;
    };
};