class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        std::priority_queue<int> pq;

        for(int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            int diff = abs(x - y);

            if(diff)
                pq.push(diff);

        }
        if(pq.empty())
            return 0;
        else
            return pq.top();
        
    }
};
