class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int x = (n%2==0)? (nums[n/2-1]+nums[n/2])/2:nums[n/2];

        int ans=0;
        for(auto val:nums) ans+=(abs(x-val));

        return ans;
    }
};