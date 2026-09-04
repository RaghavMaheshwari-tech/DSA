class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        int n = nums.size(),start=0,end=1,ans=0;
        sort(nums.begin(),nums.end());

        if(n==1) return 1;

        while(end<n){
            while(nums[start]+k < nums[end]-k){
                start++;
            }

            ans=max(ans,end-start+1);
            end++;
        }

        ans=max(ans,end-start);

        return ans;
    }
};