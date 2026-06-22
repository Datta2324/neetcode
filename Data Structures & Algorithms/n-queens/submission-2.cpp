class Solution {
public:
    // As we are placing row by row from top to bottom
    // No need to check down of the current row (As they are not filled yet)
    // Also as we are trying one col at once in the current row, no need
    // to check in the current col
    // Valid check are TOP, TOP-LEFT, TOP-RIGHT
    bool isValidPos(vector<string> &fill, int row, int col, int n,
                    vector<bool> &top, vector<bool> &tl, vector<bool> &tr)
    {
    // TOP_ LEFT (row--)(col--)
        if(tl[n-1+ row -col])
            return false;
        
    // TOP (row--)(col)
        if(top[col])
            return false;

    // TOP-RIGHT (row--)(col++)
        if(tr[row + col])
            return false;

        return true;
      
    }
    void fillQueens(vector<vector<string>> &ans,vector<string> &fill, int row, int n,
                    vector<bool> &top ,vector<bool> &tl,vector<bool> &tr)
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
            if(isValidPos(fill,row,col,n,top,tl,tr))
            {
                // Try by taking Queen in that place.
                fill[row][col] = 'Q';
                top[col] = true;
                tl[n-1+row-col] = true;
                tr[row + col] = true;

                fillQueens(ans,fill,row+1,n,top,tl,tr);
                // Try other col in the row 
                // so back track to prev stage by removing 'Q'
                // And fill the tables back to false
                fill[row][col] = '.';
                top[col] = false;
                tl[n-1+row-col] = false;
                tr[row + col] = false;
            }
        }
       

    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        // Rough board to try the possibilities.
        // And when a successful one encounters we fill it into the ans

        // Hash Table to check on the top
        vector<bool> top(n,false);
        // Hash table to check on the TOP LEFT and TOP RIGHT
        vector<bool> tl(2*n-1,false);
        vector<bool> tr(2*n-1,false);

        vector<string> fill(n, string(n,'.'));

        fillQueens(ans,fill,0,n,top,tl,tr);  
        return ans;
    }
};
