class Solution {
public:

    int r[4] = {1,0,0,-1};
    int c[4] = {0,1,-1,0};
    int M = 1e9+7;

    vector<vector<vector<int>>>dp;

    int solve(int m, int n, int move, int i, int j) {

        if(i<0 || i>=m || j<0 || j>=n) return 1;
        if(move==0) return 0;

        if(dp[i][j][move]!=-1) return dp[i][j][move];

        move--;
        long long total=0;

        for(int k=0;k<4;k++){
            int ni = i+r[k];
            int nj = j+c[k];

            total= (total + solve(m,n,move,ni,nj))%M;
        }

        move++;
        return dp[i][j][move] = total;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));

        return solve(m,n,maxMove,startRow,startColumn);
    }
};