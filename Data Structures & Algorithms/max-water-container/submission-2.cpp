class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l = 0;
        int r = heights.size() - 1;
        int maxArea = 0;

        while(l < r)
        {
            int area = min(heights[l] , heights[r]) * (r - l);
            if(area > maxArea)
                maxArea = area;
            heights[l] <= heights[r] ? l++ : r--;
        }
        return maxArea;
        
    }
};
