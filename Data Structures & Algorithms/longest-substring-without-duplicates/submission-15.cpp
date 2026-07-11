class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char,int> um;
        int maxLen = 0;
        int l = 0;
        int r = 0;
        while(l <= r && r < s.size())
        {
            if(um.contains(s[r]))
                // l = um[s[r]] + 1;
                l = max(l, um[s[r]] + 1);
            
            um[s[r]] = r;
            r++;
            maxLen = max(maxLen,r-l);

        }
        return maxLen;
        
    }
};
