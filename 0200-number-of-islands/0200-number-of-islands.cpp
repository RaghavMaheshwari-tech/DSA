class Solution {
public:
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};

    int n,m;

    bool valid(int &x, int &y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    void solve(int r, int c, vector<vector<char>>& grid){
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c]='0';

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=x+row[k];
                int nc=y+col[k];

                if(valid(nr,nc) && grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    grid[nr][nc]='0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    solve(i,j,grid);
                }
            }
        }

        return ans;
    }
};