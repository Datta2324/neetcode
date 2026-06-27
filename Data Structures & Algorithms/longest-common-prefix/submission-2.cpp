class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string ans = "";
        int count = 0;
        bool flag = false;
        while(true)
        {
            if (count == strs[0].size())
                return ans;
            char a;
            a = strs[0][count];
            for(int i = 0; i < strs.size(); i++)
            {
                if(strs[i][count] != a)
                {
                    flag = true;
                    break;
                }
            }
           
            if(flag)
                break;

            ans+=strs[0][count];
                count++;

        }
            return ans;
    }
};