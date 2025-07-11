#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) {
            return "";
        }
        
        int n = s.length();
        int start = 0;
        int maxLength = 1;
        
        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int currentMaxLen = std::max(len1, len2);
            
            if (currentMaxLen > maxLength) {
                start = i - (currentMaxLen - 1) / 2;
                maxLength = currentMaxLen;
            }
        }
        
        return s.substr(start, maxLength);
    }
    
private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        int n = s.length();
        
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
};