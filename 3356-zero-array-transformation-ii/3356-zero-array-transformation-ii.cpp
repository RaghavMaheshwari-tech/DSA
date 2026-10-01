class Solution {
public:

    bool solve(vector<int>&nums,vector<vector<int>>&queries, int k){
        vector<int>arr(nums.size()+1,0);

        for(int i=0;i<=k;i++){
            int s=queries[i][0];
            int e=queries[i][1];
            int val=queries[i][2];

            arr[s]+=val;
            arr[e+1]-=val;
        }

        for(int i=0;i<nums.size();i++){
            if(i>0) arr[i]+=arr[i-1];
            
            if(arr[i]<nums[i]) return 0;
        }

        return 1;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size();
        int start=0,end=m-1,ans=-1;

        if(*max_element(nums.begin(),nums.end())==0) return 0;

        while(start<=end){
            int k = start+(end-start)/2;

            if(solve(nums,queries,k)){
                ans = k+1;
                end= k-1;
            }
            else start=k+1;
        }

        return ans;
    }
};