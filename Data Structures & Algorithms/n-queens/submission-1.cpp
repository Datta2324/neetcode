class Solution {
public:
    // As we are placing row by row from top to bottom
    // No need to check down of the current row (As they are not filled yet)
    // Also as we are trying one col at once in the current row, no need
    // to check in the current col
    // Valid check are TOP, TOP-LEFT, TOP-RIGHT
    bool isValidPos(vector<string> &fill, int row, int col, int n)
    {
        int dupRow = row;
        int dupCol = col;
    // TOP_ LEFT (row--)(col--)
        while((row>=0) && (col >= 0))
        {
            if(fill[row][col] == 'Q')
                return false;
            
            row--;
            col--;
        }
        row = dupRow;
        col = dupCol;
    // TOP (row--)(col)
        while(row >= 0)
        {
            if(fill[row][col] == 'Q')
                return false;
            
            row--;
        }
        row = dupRow;
        col = dupCol;
    // TOP-RIGHT (row--)(col++)
        while((row >= 0) && (col < n) )
        {
            if(fill[row][col] == 'Q')
                return false;
            row--;
            col++;
        }

        return true;
      
    }
    void fillQueens(vector<vector<string>> &ans,vector<string> &fill, int row, int n)
    {
        if(row == n)
        {
            ans.emplace_back(fill);
            return;
        }
        // Row traversal by recurssion and 
        // in that row try all the cols by the for loop
        for(int col = 0; col < n; col++)
        {
            if(isValidPos(fill,row,col,n))
            {
                // Try by taking Queen in that place.
                fill[row][col] = 'Q';
                fillQueens(ans,fill,row+1,n);
                // Try other col in the row 
                // so back track to prev stage by removing 'Q'
                fill[row][col] = '.';
            }
        }
       

    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        // Rough board to try the possibilities.
        // And when a successful one encounters we fill it into the ans
        vector<string> fill(n, string(n,'.'));

        fillQueens(ans,fill,0,n);  
        return ans;
    }
};
