class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> um;  

        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            //um.count() to check the existence we can use find also
            if (um.find(s[r]) != um.end() && um[s[r]] >= l) {
                l = um[s[r]] + 1;
            }

            um[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};