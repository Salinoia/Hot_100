#include <string>
#include <unordered_map>
#include <climits>
using std::string;
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size() || s.size() == 0 || t.size() == 0){
            return {};
        }
        std::unordered_map<char, int> u_mapT;
        std::unordered_map<char, int> u_mapS;
        for(char ch : t) u_mapT[ch]++;
        int tCount = u_mapT.size();
        int count = 0;
        int start = 0, min_len = INT_MAX;
        int left = 0, right = 0;
        while(right < s.size()){
            char r_ch = s[right];
            if(u_mapT.count(r_ch)){
                u_mapS[r_ch]++;
                if(u_mapS[r_ch] == u_mapT[r_ch]){
                    count++;
                }
            }

            while(count == tCount){
                if(right - left + 1 < min_len){
                    min_len = right - left + 1;
                    start = left;
                }
                char l_ch = s[left];
                if(u_mapT.count(l_ch)){
                    u_mapS[l_ch]--;
                    if(u_mapS[l_ch] < u_mapT[l_ch]){
                        count--;
                    }
                }
                left++;
            }
            right++;
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};