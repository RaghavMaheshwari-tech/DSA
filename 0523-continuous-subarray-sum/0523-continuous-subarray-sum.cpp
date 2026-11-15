class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        long long sum=0;

        mp[0]=-1;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            int x=sum%k;

            if(mp.find(x)!=mp.end()){
                if(i-mp[x]>=2) return 1;
            }
            else mp[x] = i;
        }

        return 0;
    }
};