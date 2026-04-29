class Solution {
public:
    int characterReplacement(string s, int k) {

        if(s.size() == 0)
            return 0;
        if(s.size() == k)
            return k;
       
        int l = 0;
        int r = 0;

        int freq[26] = {0};
        int maxFreq = 0;
        int winSize = 0;
        int maxLen = 0;

        while(r < s.size())
        {
            freq[s[r] - 'A']++;
            maxFreq = max(freq[s[r] - 'A'], maxFreq);
            winSize = r - l + 1;
            
            if((winSize - maxFreq) > k)
            {
                freq[s[l] - 'A']--;
                l++;
                winSize = r - l + 1;
            }
            maxLen = max(winSize, maxLen);
            r++;
        }
        return maxLen;
    }
};
