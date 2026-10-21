class Solution {
public:
    int total=0;
    void solve(int i, int &x, vector<int>&nums){

        if(i==nums.size()){
            total+=x;
            return;
        }

        solve(i+1,x,nums);
        x^=nums[i];
        solve(i+1,x,nums);
        x^=nums[i];
    }
    int subsetXORSum(vector<int>& nums) {
        int x = 0;
        solve(0,x,nums);
        return total;
    }
};