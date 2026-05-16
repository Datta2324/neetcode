class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars(position.size());

        for(int i = 0; i < position.size(); i++) {
            cars[i] = {position[i], speed[i]};
        }

        // sort by position descending
        sort(cars.begin(), cars.end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });

        stack<double> st;

        for(int i = 0; i < cars.size(); i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;

            // if current car catches up → ignore (merge)
            if(!st.empty() && time <= st.top()) {
                continue;
            }

            // new fleet
            st.push(time);
        }

        return st.size();
    }
};