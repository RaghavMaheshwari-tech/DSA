class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<long long,int>mp;

        long long sum=0;
        mp[0]=1;
        int ans=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int x = sum%k;
            if(x<0) x+=k;

            if(mp.find(x)!=mp.end()){
                ans+=mp[x];
            }
            mp[x]++;
        }

        return ans;
    }
};