class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool isPalin(string& s,int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void dfs(int pos,string& s, int n)
    {
        if(pos == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i = pos; i < n; i++)
        {
            if(isPalin(s, pos, i))
            {
                temp.push_back(s.substr(pos,i-pos+1));
                dfs(i+1,s,n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dfs(0,s,n);
        return ans;
    }
};
