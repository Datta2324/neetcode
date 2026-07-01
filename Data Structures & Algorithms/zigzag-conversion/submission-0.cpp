class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<string> ans(numRows);
        int i = 0;
        while(n)
        {
            int p = 0;
            while( n && (p < numRows))
            {
                ans[p]+= s[i];
                i++;
                p++;
                n--;
            }
            p = numRows - 2;
            while(n && p)
            {
                ans[p] += s[i];
                i++;
                p--;
                n--;
            }
        }
        for(int i = 1; i < numRows;i++)
        {
            ans[0]+=ans[i];
        }

        return ans[0];
    }
};