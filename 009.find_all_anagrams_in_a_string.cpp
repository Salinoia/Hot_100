#include <vector>
#include <string>
#include <unordered_map>
using std::string;
using std::vector;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int p_size = p.size();
        int s_size = s.size();
        std::unordered_map<char, int> hash;
        for(char ch : p){
            hash[ch]++;
        }
        vector<int> res;
        if(s_size < p_size){
            return res;
        }
        int left = 0, right = 0;
        int count = p_size;
        while(right < s_size){
            char right_char = s[right];

            // 如果右指针字符在 p 中，减少哈希表中的计数
            if(hash.find(right_char) != hash.end()){
                if(hash[right_char] > 0){
                    count--;
                }
                hash[right_char]--;
            }

            // 窗口大小等于 p 的长度时，检查是否为异位词
            if(right - left + 1 == p_size){
                if(count == 0){
                    res.emplace_back(left);
                }

                char left_char = s[left];
                // 如果左指针字符在 p 中，增加哈希表中的计数
                if(hash.find(left_char) != hash.end()){
                    if(hash[left_char] >= 0){
                        count++;
                    }
                    hash[left_char]++;
                }
                left++;
            }
            right++;
        }
        return res;
    }
};