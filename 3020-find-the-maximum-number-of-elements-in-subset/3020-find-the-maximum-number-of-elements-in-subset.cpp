class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int>mp;//no. , frequency
        unordered_set<int>st;
        sort(nums.begin(),nums.end());

        for(auto v:nums){
            mp[v]++;
            st.insert(v);
        }

        int ans=1;
        //1 wala case
        if(mp.count(1)){
            int val = mp[1];
            if(val%2==0) ans = max(ans,val-1);
            else ans= max(ans,val);
            st.erase(1);
        }
        

        for(int i=0;i<n;i++){
            long long x = nums[i];
            int cnt=0;
            
            while(st.count(x) && mp.count(x)){
                cnt++;
                if(mp[x]<2) break; 
                st.erase(x);
                x*=x;
            }

            if(cnt>1) ans=max(ans,cnt*2-1);
        }

        return ans;
    }
};