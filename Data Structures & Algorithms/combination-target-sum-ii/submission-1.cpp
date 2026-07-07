class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int pos,vector<int> &cand, int tar)
    {

        if(tar == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(pos == cand.size() || tar < 0)
        {
            return;
        }

        for(int i = pos; i < cand.size(); i++)
        {
            if((i > pos) && (cand[i] == cand[i - 1]))
                continue;

            temp.push_back(cand[i]);
            dfs(i + 1,cand,tar - cand[i]);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,candidates,target);
        return ans;
    }
};
