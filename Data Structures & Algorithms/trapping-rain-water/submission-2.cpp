class Solution {
   public:
    int rightMax(int i , vector<int>& height, int n)
    {
        int updated = -1;
        int rm =  i;
        
        while(i < n)
        {
            if(height[i] >=height[rm])
            {
                rm = i;
                updated = i;
            }
            i++;
        }

        return updated;

    }
    // int rightMax(int i, vector<int>& height, int n) {
    //     int rm = -1;

    //     for (int j = i + 1; j < n; j++) {
    //         if (rm == -1 || height[j] > height[rm]) 
    //             rm = j;
    //     }

    //     return rm;
    // }
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        while (l < n && height[l] == 0) l++;

        int lm = l;
        int rm = l - 1;
        int count = 0;

        for (int i = l; i < n; i++) {
            // Find right max
            if (rm <= i) rm = rightMax(i + 1, height, n);

            if (rm == -1) continue;

            count += max(0, (min(height[lm], height[rm]) - height[i]));
            if (height[i] > height[lm]) lm = i;
        }

        return count;
    }
};
