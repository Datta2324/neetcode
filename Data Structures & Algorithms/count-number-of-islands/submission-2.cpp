class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i , int j,int n, int m)
    {
        int dirs[4][2] = {{1,0}, {0,1}, {-1,0},{0,-1}};
        vis[i][j] = 1;

        for(auto &d : dirs)
        {
            int nx = i + d[0];
            int ny = j + d[1];

            if(nx>=0 && ny >=0 && nx < n && ny < m)
            {
                if(vis[nx][ny] == 0 && grid[nx][ny] == '1')
                {
                    dfs(grid, vis, nx , ny,n,m);
                }

            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int  count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j ++)
            {
                if((grid[i][j] == '1') && (vis[i][j] ==0))
                {
                    cout<<i<<" "<<j<< "\n";
                    count++;
                    dfs(grid, vis, i , j,n,m);
                }
            }
        }
        return count; 
    }
};
