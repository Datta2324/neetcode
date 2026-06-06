class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dirs[4][2] = {{1,0}, {0,1}, {-1,0},{0,-1}};
        vector<vector<int>> vis(m,vector<int>(n,0));
        std::queue<pair<int,int>> q;
        int ans = 0;

        for(int i = 0; i <m;i++ )
        {
            for(int j = 0;j < n; j++)
            {
                if(vis[i][j] == 0){
                    if(grid[i][j] == '0')
                    {
                        continue;
                    }
                    else
                    {
                            vis[i][j] = 1;
                            q.push({i,j});
                            ans++;

                        while(!q.empty())
                        {
                        auto [x,y] = q.front();
                        q.pop();
                            for(auto &d : dirs)
                            {
                                int nx = x + d[0];
                                int ny = y + d[1];
                                if(nx >= 0 && nx < m && ny >=0 && ny < n)
                                {
                                    if((grid[nx][ny] == '1') && (vis[nx][ny] == 0))
                                    {
                                        vis[nx][ny] = 1;
                                        q.push({nx,ny});
                                    }
                                }
                            }
                        }
                }
            }
        
        }
        }
    return ans;
    }
};
