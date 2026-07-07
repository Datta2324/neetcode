class Solution {
public:
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    bool dfs(int m, int n, int i, int j, int pos, string &word,vector<vector<char>>& board)
    {
        if(word[pos] != board[i][j])
            return false;

        if(pos == word.size() - 1)
            return true;
    
        bool ans = false;
         char temp = board[i][j];
        board[i][j] = '#';
        for(auto x : dirs)
        {
            int nx = x[0] + i;
            int ny = x[1] + j;

            if((nx >= 0) && (nx < m) && (ny >=0) && (ny < n) && (board[nx][ny] != '#'))
                ans = dfs(m,n,nx,ny,pos+1,word,board);
            if(ans)
            {
               board[i][j] = temp; 
               return true;
            }
        }
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0 ; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0])
                {
                    bool ans = dfs(m,n,i,j,0,word,board);
                    if(ans)
                        return true;
                }
            }
        }
        return false;
    }
};
