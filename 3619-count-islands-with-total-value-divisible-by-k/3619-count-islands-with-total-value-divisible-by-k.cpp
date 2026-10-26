class Solution {
public:
    int n,m;
    int row[4] = {1,0,0,-1};
    int col[4] = {0,1,-1,0};

    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    int solve(int r,int c, vector<vector<int>>& grid, int w){
        queue<pair<int,int>>q;
        q.push({r,c});
        
        long long sum=grid[r][c];
        grid[r][c]=0;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=x+row[k];
                int nc=y+col[k];

                if(valid(nr,nc) && grid[nr][nc]!=0){
                    sum+=grid[nr][nc];
                    grid[nr][nc]=0;
                    q.push({nr,nc});
                }
            }
        }

        return sum%w==0;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) ans+=solve(i,j,grid,k);
            }
        }

        return ans;
    }
};