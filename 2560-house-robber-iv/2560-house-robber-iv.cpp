class Solution {
public:
    bool check(int &mid, vector<int>&nums, int &k){
        int n = nums.size();
        int houses=0;
        int prev=-2;

        for(int i=0;i<n;i++){
            if(nums[i]<=mid && prev<i-1){
                houses++;
                prev=i;
            }
        }

        return houses>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int start = *min_element(nums.begin(),nums.end());
        int end = *max_element(nums.begin(),nums.end());

        int ans=end;
        
        while(start<=end){
            int mid=start+(end-start)/2;

            if(check(mid,nums,k)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return ans;
    }
};