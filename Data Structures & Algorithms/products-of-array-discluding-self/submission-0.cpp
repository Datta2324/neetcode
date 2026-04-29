class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        vector<int> ans(nums.size(),0);
        int zeroIndex;
        int product = 1;

        for(int i=0; i< nums.size();i++)
        {
            if(nums[i] == 0)
            {
                zeroCount++;
                zeroIndex = i;
            }
            else
                product*= nums[i];
            if(zeroCount > 1)
                return ans;
        }
        if(zeroCount == 0 )
        {
            for(int i=0; i< nums.size();i++)
                ans[i] = product/nums[i];
        }
        else if(zeroCount == 1)
            ans[zeroIndex] = product;

        return ans;
    }
};
