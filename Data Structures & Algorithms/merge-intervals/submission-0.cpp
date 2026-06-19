class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& vec) {
        vector<vector<int>> ans;
        sort(vec.begin(),vec.end());
        ans.emplace_back(vec[0]);
        for(auto i = vec.begin()+1 ; i != vec.end(); i++)
        {
            if((*i)[0] <= ans.back()[1])
                ans.back()[1] = max((*i)[1],ans.back()[1] );
            else
                ans.emplace_back((*i));

        }
        return ans;
        
    }
};
