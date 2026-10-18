class Solution {
public:
    int solve(int i,int k, int n, unordered_map<int,int>&st,vector<int>&nums){

        if(i==nums.size()){
            if(st.size()>=1) return 1;
            else return 0;
            
        }

        //not take it
        int left = solve(i+1,k,n,st,nums);
        //take it
        int x = nums[i]+k;
        int y = nums[i]-k;
        int right =0;

        if(st[x]==0 && st[y]==0){
            st[nums[i]]++;
            right = solve(i+1,k,n,st,nums);
            st[nums[i]]--;
        }

        return left+right;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>st;
        return solve(0,k,n,st,nums);
    }
};