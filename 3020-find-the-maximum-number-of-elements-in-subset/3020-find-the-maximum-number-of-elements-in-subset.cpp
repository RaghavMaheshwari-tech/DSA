class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int>mp;//no. , frequency

        for(auto v:nums){
            mp[v]++;
        }

        int ans=1;
        if(mp.count(1)){
            int val = mp[1];
            if(val%2==0) ans = max(ans,val-1);
            else ans= max(ans,val);
        }
        

        for(int i=0;i<n;i++){
            long long x = nums[i];
            if(x==1) continue;
            int cnt=0;
            

            while(mp.count(x)){
                cnt++;
                if(mp[x]<2) break; 
                x*=x;
            }

            if(cnt>1) ans=max(ans,cnt*2-1);
        }

        return ans;
    }
};