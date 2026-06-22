class Solution {
public:
    bool possible(vector<int>&piles,int num, int h)
    {
        int count = 0;
        for(int i = 0; i <piles.size();i++)
        {
            count += (piles[i] + num - 1) / num;
        }
        if(count <= h)
            return true;
        
        return false;


    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int l = 1;
        int r = piles[piles.size()-1];
        int ans = h;

        while(l <= r)
        {
           int mid = (l+r)/2;
            if(possible(piles,mid,h))
            {
                r = mid - 1;
                ans = mid;
            }
            else
                l = mid + 1;

        }
        return ans;
        
    }
};
