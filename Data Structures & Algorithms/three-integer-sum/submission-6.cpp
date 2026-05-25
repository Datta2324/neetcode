class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ;i < nums.size(); i++)
        {
            
            if((i!=0 ) && (nums[i] == nums[i-1]))
                continue;
            int l = i + 1;
            int r = nums.size() - 1;
            int target = 0 - nums[i];

            while(l < r)
            {
                if( nums[l] + nums[r] < target)
                {
                    l++;
                }
                else if ( nums[l] + nums[r] > target)
                {
                    r--;
                }
                else
                {
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[l]);
                    res.push_back(nums[r]);

                    l++;
                    r--;

                    ans.push_back(res);
                    while((l < r ) && (nums[r] == nums[r+1]))
                        r--;
                    while((l < r ) && (nums[l] == nums[l-1]))
                        l++;
                }
            }

        }
        return ans;
        
    }
};
