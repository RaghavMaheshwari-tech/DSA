class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>temp_c(m,0);
        vector<int>temp_r(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    temp_c[j]+=1;
                    temp_r[i]+=1;
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (temp_c[j]>1 || temp_r[i]>1)){
                    ans++;
                }
            }
        }

        return ans;
    }
};