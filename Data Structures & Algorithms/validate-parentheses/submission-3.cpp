class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        int n = s.size();
        int i = 0;

        while(i < n)
        {
            if(s[i] == '(' ||  s[i] == '{'|| s[i] == '[')
            {
                st.push(s[i]);
            }

            if( s[i] == ')'||  s[i] == '}'|| s[i] == ']')
            {
                if(st.empty())
                    return false;
                    
                char topChar = st.top();
                st.pop();

                switch(s[i])
                {
                    case ')' : if(topChar != '(') return false; break;
                    case '}' : if(topChar != '{') return false; break;
                    case ']' : if(topChar != '[') return false; break;
                }
            }
            i++;
        }
        if(st.empty())
            return true;
        else
            return false;
        
    }
};
