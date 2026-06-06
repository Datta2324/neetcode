/*
2 1 1    2 2 1
1 1 0  - 2 1 0
0 1 1    0 1 1
*/
class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = -1;
        queue<pair<int,int>> q;
        
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        // vector<vector<int>> vis(m,vector<int>(n,0));
        // Pushing source nodes into queue
        for(int i = 0; i <m; i++)
        {
            for(int j = 0; j< n; j++)
            {
                if(grid[i][j] == 2)
                {
                    grid[i][j] = -1;
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                    freshCount++;
            }
        }

        if(!freshCount)
            return 0;

        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            int size = q.size();

            while(size)
            {
                auto [x,y]= q.front();
                q.pop();

                for(auto &d : dirs)
                {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && nx <m && ny >= 0 && ny <n)
                    {
                            if(grid[nx][ny] == 1)
                            {   
                                grid[nx][ny] = -1;
                                q.push({nx,ny});
                                freshCount --;
                            }
                    
                    }
                }
                size--;
            }
            time++;
        }
        if(freshCount)
            return -1;
        else
            return time;
    }
};
