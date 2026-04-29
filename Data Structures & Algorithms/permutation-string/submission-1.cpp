class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s2.size() < s1.size())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        int winSize = s1.size();
        int temp = winSize;

        for(int i = 0; i< winSize; i++)
            freq1[s1[i] - 'a']++;

        int l = 0;
        int r = 0;


        while(temp)
        {
            freq2[s2[r] - 'a'] ++;
            r++;
            temp--;
        }
        if(freq1 == freq2)
            return true;
        while(r < s2.size())
        {
            freq2[s2[l] - 'a'] --;
            l++;
            freq2[s2[r] - 'a']++;
            r++;

            if(freq1 == freq2)
                return true;
        }
        return false;
    }
};
