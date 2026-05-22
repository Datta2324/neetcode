class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size()- 1;
        int n = matrix[0].size() - 1;

        int i = 0;
        while(i <= m)
        {
            if(target > matrix[i][n])
                i++;
            else
                break;
        }
        if(i > m)
            return false;
        // Target might be in the ith row
        int l = 0;
        int r = n;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(matrix[i][mid] == target)
                return true;
            else if(matrix[i][mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
        
    }
};
