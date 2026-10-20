class Solution {
public:
    int n,m;
    int r[4] = {1,0,0,-1};
    int c[4] = {0,-1,1,0};
    
    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    int find(int i,int j,vector<vector<int>>& grid, vector<vector<bool>>& visited){

        if(grid[i][j]==0) return 0;

        visited[i][j]=1;

        int maxi = 0;

        for(int k=0;k<4;k++){
            int ni=i+r[k];
            int nj = j+c[k];

            if(valid(ni,nj) && !visited[ni][nj]){
                maxi = max(maxi,find(ni,nj,grid,visited));
            }
        }

        visited[i][j]=0;

        return grid[i][j]+maxi;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    ans = max(ans,find(i,j,grid,visited));
                }
            }
        }

        return ans;
    }
};