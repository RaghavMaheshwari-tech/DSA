class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>>dp;
    int find(int sum, int n, int k, int target){
        if(sum>target) return 0;
        if(n==0){
            if(sum==target) return 1;
            else return 0;
        }

        if(dp[sum][n]!=-1) return dp[sum][n];

        long long total=0;

        for(int i=1;i<=min(target,k);i++){
            sum+=i;
            total = (total + find(sum,n-1,k,target))%M;
            sum-=i;
        }

        return dp[sum][n] =  total;
    }
    int numRollsToTarget(int n, int k, int target) {
        if(k*n<target) return 0;
        if(k*n==target) return 1;

        dp.assign(901,vector<int>(31,-1));
        return find(0,n,k,target);
    }
};