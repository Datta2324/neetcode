class Solution {
public:

    // Final answer storage
    vector<vector<int>> ans;
    // Current subset being built
    vector<int> temp;

    // Recursive DFS function
    void dfs(int i, vector<int>& nums)
    {
        // BASE CASE
        // We processed all elements
        // Current temp is one complete subset
        if(i == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // TAKE CURRENT ELEMENT

        // Choose nums[i]
        temp.push_back(nums[i]);

        // Move to next index
        dfs(i + 1, nums);

        // BACKTRACK
        // Undo the previous choice
        // so skip branch starts clean
        temp.pop_back();

        // NOT TAKE CURRENT ELEMENT
        // Skip nums[i]
        dfs(i + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        // Start recursion from index 0
        dfs(0, nums);

        return ans;
    }
};