class Solution {
public:
    int sum=0;
    void solve(int i, int val, vector<int>&nums){
        if(i==nums.size()){
            sum+=val;
            return;
        }

        solve(i+1,val,nums);
        solve(i+1,val^nums[i],nums);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(0,0,nums);

        return sum;
    }
};