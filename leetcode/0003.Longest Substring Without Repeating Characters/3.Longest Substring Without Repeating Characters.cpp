class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)
            return s.size();
        set<char> ss;
        int len = 0;
        int maxLen = 0;
        int l = 0;
        int i = 0;
        for(; i < s.size(); ++i)
        {
            for(auto j = l; j < i; ++j)
            {
                if(s[j] == s[i])
                {
                    if(maxLen < i - l)
                        maxLen = i - l;
                    l = j + 1;
                    break;
                }
            }
        }
        return maxLen > i - l ? maxLen : i - l;
    }
};
