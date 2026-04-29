class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Frequency map
        unordered_map<int, int> freq;
        for (auto x : nums) {
            freq[x]++;
        }

        // Step 2: Bucket (index = frequency)
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto &p : freq) {
            int num = p.first;
            int f = p.second;
            bucket[f].push_back(num);
        }

        // Step 3: Traverse from high freq → low
        vector<int> ans;
        for (int f = n; f >= 1; f--) {
            for (int num : bucket[f]) {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }
    }
};