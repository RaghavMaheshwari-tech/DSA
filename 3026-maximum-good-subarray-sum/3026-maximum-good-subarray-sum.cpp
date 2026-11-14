class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1]+nums[i];

        unordered_map<long long,int>mp;

        long long ans = LLONG_MIN;

        for(int i=0;i<n;i++){

            long long target1=nums[i]-k;
            long long target2=nums[i]+k;

            if(mp.find(target1)!=mp.end()){
                int idx=mp[target1];

                if(idx==0) ans=max(ans,prefix[i]);
                else ans = max(ans,prefix[i]-prefix[idx-1]);
            }
            if(mp.find(target2)!=mp.end()){
                int idx=mp[target2];

                if(idx==0) ans=max(ans,prefix[i]);
                else ans = max(ans,prefix[i]-prefix[idx-1]);
            }


            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=i;
            }
            else{
                int x = mp[nums[i]];
                if(prefix[x]<prefix[i]) continue;
                else mp[nums[i]]=i;
            }
        }

        return (ans==LLONG_MIN)? 0:ans;

    }
};