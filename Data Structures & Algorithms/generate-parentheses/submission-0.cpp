class Solution {
public:
    vector<string> ans;
    string temp = "";
    void dfs(int n, int open, int close)
    {
        if(temp.size() == (2*n))
        {
            ans.push_back(temp);
            return;
        }

        if(open <  n)
        {
            temp.push_back('(');
            open++;
            dfs(n,open,close);
            temp.pop_back();
            open--;
        }
    
        if(close < open)
        {
            temp.push_back(')');
            close++;
            dfs(n,open,close);
            temp.pop_back();
            close--;
        }
        
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0);
        return ans;
        
    }
};
