class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> um;
        int presum = 0 , count = 0;
        for(int i = 0; i < nums.size();i++)
        {
            um[presum]++;
            presum += nums[i];
            int remain = presum - k;
            count+= um[remain];
        }
        return count;

        
    }
};