class Solution {
public:
    int climb(int n, vector<int> &dp)
    {
        if(n < 3 )
            return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climb(n-1,dp) + climb(n-2,dp);
            
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int ans = climb(n,dp);
        return ans;
 
    }
};
