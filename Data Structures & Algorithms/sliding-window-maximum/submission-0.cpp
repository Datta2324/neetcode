class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        int i = 0;
        while (i < k) {
            while (!dq.empty() && (nums[i] >= nums[dq.back()])) 
                dq.pop_back();

            dq.push_back(i);
            i++;
        }
        ans.push_back(nums[dq.front()]);
        while (i < nums.size()) {
            while (!dq.empty() && (dq.front() < (i - k + 1))) dq.pop_front();
            while (!dq.empty() && (nums[i] >= nums[dq.back()])) dq.pop_back();

            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
            i++;
        }
        return ans;
    }
};
