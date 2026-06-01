class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(vector<int> &nums, vector<bool> &visit)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(visit[i])
            {
                temp.push_back(nums[i]);
                visit[i] = 0;
                dfs(nums,visit);
                visit[i] = 1;
                temp.pop_back();
            }
            else
                continue;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visit(nums.size(),1);
        dfs(nums,visit);
        return ans;
        
    }
};
