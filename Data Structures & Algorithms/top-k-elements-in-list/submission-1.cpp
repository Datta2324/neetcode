class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>  um;
        map<int, vector<int>, std::greater<int>> m;
        vector<int> ans;

        for(auto i = nums.begin(); i!= nums.end(); i++)
        {
            um[*i]++;
        } 

        for(auto i = um.begin(); i != um.end();i++)
        {
            m[i->second].push_back(i->first);
        }

        // m should be sorted in descending order
        // pass through m and add values from map
        // into ans vector till vec size less than k and return
        int count = 0;
        for(auto i = m.begin() ; i!= m.end() ; i++)
        {
            for(int j = 0; j< i->second.size(); j++)
            {
                if(count < k)
                {
                    ans.push_back(i->second[j]);
                    count++;
                }
                if(count == k)
                    return ans;
             }

        }
    }
};
