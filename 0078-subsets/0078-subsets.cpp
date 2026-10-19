class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx, int n, vector<int>&temp, vector<int>&nums){
        if(idx==n){
            ans.push_back(temp);
            return;
        }

        solve(idx+1,n,temp,nums);
        temp.push_back(nums[idx]);
        solve(idx+1,n,temp,nums);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        solve(0,n,temp,nums);

        return ans;
    }
};