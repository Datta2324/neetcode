class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k == points.size())
            return points;

        std::priority_queue<vector<int>> pq;
        vector<vector<int>> ans;

        for(int i = 0 ; i < points.size(); i++)
        {
            // We can omit sqrt cause if(sqrt(x) < sqrt(y)) the x will be less than y
            // sqrt is expensive as well as ans is to be stored in double
            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            if(pq.size() < k)
            {
                pq.push({dist,i});
            }
            else
            {
                // if there is lesser dist than in pq insert else leave it
                if(dist < pq.top()[0])
                {
                    pq.pop();
                    pq.push({dist,i});
                }
            }
        }

        while(!pq.empty())
        {
            //Get index from the pq 
            int index = pq.top()[1];
            ans.push_back(points[index]);
            pq.pop();
        }

        return ans;
        
    }
};
