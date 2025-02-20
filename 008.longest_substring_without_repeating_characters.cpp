#include <string>
#include <algorithm>
class Solution{
    public:
    int lengthOfLongestSubstring(std::string s){
        int left = 0;
        int max_len = 0;
        int hash[256] = {0};
        for(int right = 0; right < s.size(); ++right){
            char current_char = s[right];
            // 如果当前字符已经出现过，并且上次出现的位置在窗口内
            if(hash[current_char] != 0 && hash[current_char] >= left){
                left = hash[current_char];
            }
            // 更新当前字符的最后出现位置
            hash[current_char] = right + 1;
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};