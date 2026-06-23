class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> ans(nums.size());
        ans[0] = 1;
        int temp = nums[0];

        for(int i = 1 ; i < nums.size(); i++)
        {
            ans[i] = temp;
            temp = temp*nums[i];
        }

        int rightside =  1;

        for(int i = nums.size() - 1; i >=0; i--)
        {
            ans[i] *= rightside;
            rightside  *= nums[i];
        }
        return ans;

    }
};
