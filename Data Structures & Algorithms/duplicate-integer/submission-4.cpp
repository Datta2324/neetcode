class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++)
        {
            if(m.contains(nums[i]) == 1 )
                return true;
            m[nums[i]] ++;
        }
        return false;
        
    }
};