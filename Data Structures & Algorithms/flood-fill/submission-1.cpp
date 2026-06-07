class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        // BFS
        if(image[sr][sc] == color)
            return image;
        int n = image.size();
        int m = image[0].size();

        std::queue<pair<int,int>> q;
        q.push({sr,sc});
        int target = image[sr][sc] ;
        image[sr][sc] = color;
        int dirs[4][2] = {{1,0}, {0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            for(auto &d : dirs)
            {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >=0 && nx <n && ny >=0 && ny < m )
                {
                    if(image[nx][ny] == target)
                    {
                        image[nx][ny] = color;
                        q.push({nx,ny});
                    }
                }
            }

        }

return image;

        
    }
};