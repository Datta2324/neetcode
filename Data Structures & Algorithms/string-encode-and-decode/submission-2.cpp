class Solution {
public:

    string encode(vector<string>& strs) {
        string enc;
        for(int i = 0 ; i< strs.size(); i++)
        {
            enc+= to_string(strs[i].size());
            enc+= "#";
            enc+= strs[i];
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i<s.size())
        {
            int j = i;
            while(s[j] != '#')
            {
                j++;
            }

            // convert string to int from i to j chars
            string len = s.substr(i,j-i);
            int length = stoi(len);
            string res="";
            // for(int x = j + 1; x< j+1+length ;x++)
            // {
            //     res+= s[x];
            // }
            res+=s.substr(j+1, length);
            i = j + 1 + length;
            ans.push_back(res);
        }
        return ans;

    }
};
