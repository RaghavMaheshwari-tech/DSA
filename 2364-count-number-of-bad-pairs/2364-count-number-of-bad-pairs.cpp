class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        int n= nums.size();
        long long total=(1LL*n*(n-1))/2;

        for(int i=0;i<n;i++) nums[i]=nums[i]-i;

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans+=mp[nums[i]];
            }
            mp[nums[i]]++;
        }

        return total-ans;
    }
};