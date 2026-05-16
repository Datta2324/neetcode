class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars(position.size());

        for(int i = 0;i < position.size(); i++)
        {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }
        sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        stack<double> st;

        for(int i = 0; i < position.size() ; i++)
        {
            double time = (double) (target - cars[i].first)/ cars[i].second ;
            if(!st.empty() && (time <= st.top()))
            {
                continue;
            }

            st.push(time);  
        }
           
        return st.size();
        
    }
};
