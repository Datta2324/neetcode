class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int x,y;

        for(int i = 0; i<tokens.size();i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                if(!st.empty())
                {
                    y = st.top();
                    st.pop();
                    x = st.top();
                    st.pop();
                    if (tokens[i] == "+") x = x + y;
                    if (tokens[i] == "-") x = x - y;
                    if (tokens[i] == "*") x = x * y;
                    if (tokens[i] == "/") x = x / y;

                    st.push(x);
                }
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
        
    }
};
