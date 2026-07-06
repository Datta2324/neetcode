class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(int i = 0; i < tasks.size(); i++)
            //store freq;
           v[tasks[i] - 'A']++; 

        priority_queue<int> pq;

        for(int i = 0; i < v.size(); i++)
        {
            if(v[i])
                pq.push(v[i]);
        }

        queue<pair<int,int>> cool;
        int count = 0;

        while(true)
        {
            while(!cool.empty())
            {
                if(count >= cool.front().second)
                {
                    pq.push(cool.front().first);
                    cool.pop();
                }
                else
                    break;
            }

            if(!pq.empty())
            {
                int top = pq.top();
                top--;
                int availabletime = count + n + 1;
                if(top)
                    cool.push({top,availabletime});
                pq.pop();
            }

            count++;
            if(!pq.size() && !cool.size())
                break;
        }
        return count;
        
    }
};
