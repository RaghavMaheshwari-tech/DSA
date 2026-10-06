class Solution {
public:

    int row[4] = {1,0,0,-1};//DLRU
    int col[4] = {0,-1,1,0};//DLRU
    int n,m;

    bool valid(int x, vector<vector<int>> &arr){

        if (arr[0][0] < x || arr[n-1][n-1] < x) return 0;

        queue<pair<int,int>>q;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc = c+col[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && arr[nr][nc]>=x && !visited[nr][nc]){
                    if(nr==n-1 && nc==n-1){
                        return 1;
                    }
                    q.push({nr,nc});
                    visited[nr][nc] = 1;
                }
            }
        }

        return 0;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>>q;
        vector<vector<int>>arr(n,vector<int>(n,n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    arr[i][j] = 0;
                }
            }
        } 

       
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            

            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc = c+col[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    if(arr[nr][nc]>arr[r][c]+1){
                        arr[nr][nc] = arr[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }

        }

        int start=0,end=n;
        int ans = 0;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(valid(mid,arr)){
                ans = mid;
                start=mid+1;
            }
            else end=mid-1;

        }

        return ans;
    }
};