class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n);//max
        vector<int>suffix(n);//min
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i=1;i<n;i++) prefix[i] = max(prefix[i-1],nums[i]);
        for(int i=n-2;i>=0;i--) suffix[i] = min(suffix[i+1],nums[i]);

        int ans = n;

        for(int i=n-1;i>=0;i--){
            if(prefix[i]-suffix[i] <= k){
                ans = min(ans,i);
            }
        }

        return (ans==n)? -1:ans;
    }
};