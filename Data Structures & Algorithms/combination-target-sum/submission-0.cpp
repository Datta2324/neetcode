class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int i, int target, vector<int> &nums)
    {
        if(target == 0)
        {
            ans.push_back(path);
            return ;
        }

        if(target < 0 || i == nums.size())
        {
            return;
        }
        // take nums[i]
        path.push_back(nums[i]);
        dfs( i, target - nums[i], nums );
        path.pop_back();

        // skip nums[i]
        dfs(i+1, target,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0,target,nums);
        return ans;
    }
};
