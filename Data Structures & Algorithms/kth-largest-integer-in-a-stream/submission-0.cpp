class KthLargest {
public:
    priority_queue<int> pq;
    int k;
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }    
    }
    
    int add(int val) {
        
        pq.push(val);
        priority_queue<int> temp = pq;
        for(int i = 0; i < k-1 ; i++)
        {
            temp.pop();
        }
        return temp.top();

        
    }
};
