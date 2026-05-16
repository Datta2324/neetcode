class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        std::stack<pair<int,int>> st;
        vector<int> op(temp.size(),0);

        for(int i = temp.size() - 1  ; i>=0 ; i--)
        {
                while((!st.empty()) && (temp[i] >= st.top().first))
                {
                    cout<<temp[i]<< "  ";
                    st.pop();
                }
                if(!st.empty())
                {
                    op[i] = st.top().second - i;
                }
            st.push({temp[i],i});
        }
        return op;
        
    }
};
