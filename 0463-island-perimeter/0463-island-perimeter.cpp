class Solution {
public:
    int row[4] = {1,0,0,-1};
    int col[4] = {0,1,-1,0};
    int n,m;

    bool valid(int x, int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int ans =0;
        queue<pair<int,int>>q;
        n = grid.size();
        m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=2;
                    break;
                }
            }
            if(q.size()>=1) break;
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc=c+col[k];

                if(valid(nr,nc) && grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                }
                else if(!valid(nr,nc) || grid[nr][nc]==0) ans++;
            }
        }

        return ans;
    }
};