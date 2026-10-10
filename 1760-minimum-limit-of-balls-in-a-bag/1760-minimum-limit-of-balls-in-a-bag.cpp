class Solution {
public:
    bool check(int mid, vector<int>&nums, int op){
        int n = nums.size();

        int required=0;

        for(int i=0;i<n;i++){
            if(nums[i]<=mid) continue;
            else{
                int x = (nums[i]%mid==0)? nums[i]/mid-1:nums[i]/mid;
                required+=x;
            }
            if(required>op) return 0;
        }

        return 1;
        
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int end = *max_element(nums.begin(),nums.end());
        int start = 1;

        int ans = end;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(check(mid,nums,maxOperations)){
                ans = mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return ans;
    }
};