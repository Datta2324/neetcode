class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int pos, vector<int>& nums)
    {

        ans.push_back(temp);

        for(int i = pos; i < nums.size(); i++)
        {
            if((i > pos) && (nums[i] == nums[i - 1]))
                continue;
            
            temp.push_back(nums[i]);
            dfs(i + 1,nums);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(0,nums);
        return ans;
    }
};
