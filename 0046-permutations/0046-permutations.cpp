class Solution {
public:
    void solve(int n, vector<bool>&visited, vector<int>&nums,vector<vector<int>>&ans,vector<int>arr){

        if(arr.size()==n){
            ans.push_back(arr);
            return;
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                arr.push_back(nums[i]);
                visited[i]=1;
                solve(n,visited,nums,ans,arr);
                arr.pop_back();
                visited[i]=0;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool>visited(n,0);
        vector<vector<int>>ans;
        vector<int>arr;

        solve(n,visited,nums,ans,arr);

        return ans;
    }
};