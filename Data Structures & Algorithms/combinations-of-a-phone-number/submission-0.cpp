#include <string>
class Solution {
public:
    vector<string> ans;
    string temp;
    void dfs(int pos, string &digits, vector<string> &vec)
    {
        if(temp.size() == digits.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < vec[(digits[pos] - '0')].size(); i++)
        {
            temp.push_back(vec[digits[pos] - '0'][i]);

            dfs(pos+1,digits,vec);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string> vec = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        dfs(0,digits,vec);
        return ans;
        
    }
};
