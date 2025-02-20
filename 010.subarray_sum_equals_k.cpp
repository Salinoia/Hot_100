#include <vector>
#include <unordered_map>
using std::vector;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, prefix = 0;
        std::unordered_map<int, int> hash;
        hash[0] = 1;
        for(auto& num : nums){
            prefix += num;
            if(hash.find(prefix - k) != hash.end()){
                count += hash[prefix - k];
            }
            hash[prefix]++;
        }
        return count;
    }
};