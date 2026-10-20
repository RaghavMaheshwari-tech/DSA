class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>>dp;

    int numRollsToTarget(int n, int k, int target) {
        if(k*n<target) return 0;
        if(k*n==target) return 1;

        dp.assign(n*k+1,vector<int>(n+1,-1));

        for(int i=target+1;i<=n*k;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=0;
            }
        }
        dp[target][0] = 1;
        for(int i=0;i<target;i++) dp[i][0] = 0;

        for(int sum=target;sum>=0;sum--){
            for(int x=1;x<=n;x++){

                long long total=0;

                for(int i=1;i<=min(target,k);i++){
                    if(sum+i>target) break;
                    sum+=i;
                    total = (total + dp[sum][x-1])%M;
                    sum-=i;
                }

                dp[sum][x] =  total;
            }
        }
        return dp[0][n];
    }
};