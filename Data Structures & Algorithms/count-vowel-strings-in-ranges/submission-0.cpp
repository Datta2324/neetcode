class Solution {
public:
    bool isVowel(char x)
    {
        if(x == 'a' || x == 'e'||x =='i'||x == 'o'|| x=='u')
            return true;
        else
            return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size());
        int pre = 0;
        int j = 0;
        for(auto &i : words)
        {
            if(isVowel(i[0]) &&  isVowel(i[i.size() - 1]))
                pre++;
            prefixSum[j] = pre;
            j++;
        }
        vector<int> ans(queries.size());
        j = 0;
        for(auto &i : queries)
        {
            if(i[0] == 0)
                ans[j] = prefixSum[i[1]];
            else   
                ans[j] = prefixSum[i[1]] - prefixSum[i[0] - 1];

            j++;
        }
        return ans;   
    }
};