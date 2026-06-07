class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> us(nums.size());
        int len = 0;
        int max_len = 0;

        for(int i =0 ; i<nums.size();i++)
            us.insert(nums[i]);

        for (auto it = us.begin(); it != us.end(); ++it)
        {
            if(us.find(*it - 1) != us.end()) 
                continue;
            else
            {
                len = 1;
                int ele = *it + 1;
                while(us.find(ele) != us.end())
                {
                    len++;
                    ele++;
                }
                if(len > max_len)   
                    max_len = len;
            }

        }
        return max_len;

        
    }
};
