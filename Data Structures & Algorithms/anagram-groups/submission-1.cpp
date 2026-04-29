class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        vector<vector<string>> v;

        for (int i = 0; i < strs.size(); i++)
        {     
            vector<int> freq(26, 0);        
            for(int j = 0 ; j < strs[i].size() ; j++)
            {
                freq[strs[i][j] - 'a']++;
            }
            m[freq].push_back(strs[i]);
        }

        for(auto it = m.begin(); it != m.end(); it++)
        {
            //copy  values from map to vector 
            v.push_back(it->second);
        }

        return v;
        
    }
};
