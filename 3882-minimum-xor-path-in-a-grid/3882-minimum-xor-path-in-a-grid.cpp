class Solution {
public:
    int n,m;
    vector<vector<vector<int>>>dp;
    int solve(int i, int j, int val,vector<vector<int>>& grid){

        val^=grid[i][j];

        if(i==n-1 && j==m-1) return val;

        if(dp[i][j][val]!=-1) return dp[i][j][val];
        
        int right=INT_MAX,down=INT_MAX;
        
        if(i+1<n) right = solve(i+1,j,val,grid);
        if(j+1<m) down = solve(i,j+1,val,grid);

        return dp[i][j][val] = min(right,down);
    }
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(1024,-1)));
        return solve(0,0,0,grid);
    }
};