class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityEle = nums[0];
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                majorityEle = nums[i];
                count++;
            }
            else
            { 
                if(majorityEle != nums[i])
                    count --;
                else
                    count++;
            }

        }
        return majorityEle;
        
    }
};