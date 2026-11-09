class Solution {
public:

    int row[4] = {0,-1,1,0};
    int col[4] = {1,0,0,-1};
    int n,m;

    bool valid(int x, int y){
        return x>=0 && x<n && y>=0 && y<m;
    }


    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        n = isWater.size();
        m = isWater[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    isWater[i][j]=0;
                }
                else isWater[i][j]=-1;
            }
        }

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];

                if(valid(nr,nc) && isWater[nr][nc]==-1){
                    isWater[nr][nc] = isWater[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

        return isWater;
    }
};