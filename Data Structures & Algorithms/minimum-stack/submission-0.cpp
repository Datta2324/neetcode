class MinStack {
    std::stack<pair<int,int>> st;
public:
    MinStack() {
       
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push({val,val});
        }
        else
        {
            int curMin = st.top().second;
            st.push({val,min(val,curMin)});
        } 
    }
    
    void pop() {
        if(!st.empty())
        {
            st.pop();
        }
        
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
        
    }
};
