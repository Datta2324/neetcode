class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size());
        ans[arr.size() - 1] = -1;
        int maxVal = arr[arr.size() - 1];
        for(int i = arr.size() - 2; i >= 0; i--)
        {
            maxVal = max(maxVal,arr[i + 1]);
            ans[i] = maxVal;
            
        }
        return ans;
        
    }
};