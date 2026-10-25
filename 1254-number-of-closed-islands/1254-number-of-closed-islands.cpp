class Solution {
public:
    vector<vector<int>>visited;
    int n,m;
    int row[4] = {1,0,0,-1};
    int col[4] = {0,1,-1,0};

    bool valid(int x, int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    void find(int x, int y,vector<vector<int>>& grid){

        queue<pair<int,int>>q;
        q.push({x,y});
        grid[x][y]=1;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){

                int nr = r+row[k];
                int nc = c+col[k];

                if(valid(nr,nc) && grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i=0;i<m;i++){
            if(grid[0][i]==0) find(0,i,grid);
            if(grid[n-1][i]==0) find(n-1,i,grid);
        }
        for(int i=1;i<n-1;i++){
            if(grid[i][0]==0) find(i,0,grid);
            if(grid[i][m-1]==0) find(i,m-1,grid);
        }

        int ans=0;

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                    ans++;
                    find(i,j,grid);
                }
            }
            
        }

        return ans;
    }
};