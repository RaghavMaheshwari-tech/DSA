class Solution {
public:
    int r[8] = {-2,-2,-1,-1,1,1,2,2};
    int c[8] = {-1,1,2,-2,2,-2,-1,1};
    vector<vector<vector<double>>>dp;

    double solve(int &n, int w, int x, int y){

        if(x<0 || x>=n  || y<0 || y>=n){
            return 0.0;
        }

        if(w==0){
            return 1.0;
        }

        if(dp[x][y][w]!=-1) return dp[x][y][w];

        double prob=0;

        for(int k=0;k<8;k++){
            int nr= x+r[k];
            int nc= y+c[k];

            prob+=(solve(n,w-1,nr,nc));
        }

        

        return dp[x][y][w] = prob/8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        
        if(k==0) return 1.0;
        dp.assign(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        return solve(n,k,row,column);

    }
};