class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        if(size > 0)
        {
            size *= 2;
            vector<int> ans(size);
            for(int i = 0; i < size/2; i++)
            {
                ans[i] = nums[i];
                ans[i + (size/2)] = nums[i];
            }
            return ans;
        }
        return {};
        
    }
};