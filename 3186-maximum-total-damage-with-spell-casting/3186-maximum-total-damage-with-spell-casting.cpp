class Solution {
public:
    typedef long long ll;
    vector<ll>dp;
    ll solve(int i,vector<int> &arr, unordered_map<int,ll> &mp){

        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        ll take = 0,not_take=0;
        //take
        int x = lower_bound(arr.begin(),arr.end(),arr[i]+3)-arr.begin();
        take = mp[arr[i]] + solve(x,arr,mp);
        //not take
        not_take = solve(i+1,arr,mp);

        return dp[i] =  max(not_take,take);
    }
    
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,ll>mp;
        for(int p:power) mp[p]+=p;
        ll ans=0;
        

        vector<int>arr;
        for(auto &[key,val]:mp){
            arr.push_back(key);
        }

        

        sort(arr.begin(),arr.end());
        dp = vector<ll>(arr.size()+1,-1);

        return solve(0,arr,mp);
        


    }
};