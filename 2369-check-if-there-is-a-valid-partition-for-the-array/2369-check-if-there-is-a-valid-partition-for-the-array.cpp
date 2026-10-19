class Solution {
public:
    int n;
    vector<int>dp;
    // bool solve(int idx, vector<int>&nums){

    //     if(idx==n) return 1;

    //     if(dp[idx]!=-1) return dp[idx];

    //     int two=0,three=0;

    //     if(idx+2<=n && nums[idx]==nums[idx+1]){
    //         two = solve(idx+2,nums);
    //     }

    //     if(idx+3<=n && ((nums[idx]==nums[idx+1] && nums[idx+1]==nums[idx+2]) || (nums[idx]+1==nums[idx+1] && nums[idx+1]+1==nums[idx+2]))){
    //         three = solve(idx+3,nums);
    //     }

    //     return dp[idx] =  two || three;
    // }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        dp = vector<int>(n+1,-1);

        dp[n] = 1;

        for(int idx=n-1;idx>=0;idx--){
            int two=0,three=0;

            if(idx+2<=n && nums[idx]==nums[idx+1]){
                two = dp[idx+2];
            }

            if(idx+3<=n && ((nums[idx]==nums[idx+1] && nums[idx+1]==nums[idx+2]) || (nums[idx]+1==nums[idx+1] && nums[idx+1]+1==nums[idx+2]))){
                three = dp[idx+3];
            }

            dp[idx] =  two || three;
        }

        return dp[0];
    }
};