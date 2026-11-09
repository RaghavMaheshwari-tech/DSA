class Solution {
public:
    typedef long long ll;

    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        vector<ll > prefix1(n,0),prefix2(n,0);
        prefix1[0]=grid[0][0];
        prefix2[0]=grid[1][0];

        for(int i=1;i<n;i++){
            prefix1[i]=grid[0][i]+prefix1[i-1];
            prefix2[i]=grid[1][i]+prefix2[i-1];
        }

        ll ans = LLONG_MAX;

        for(int i=0;i<n;i++){
            if(i==0) ans = min(ans,prefix1[n-1]-prefix1[0]);
            else{
                ll maxi = max(prefix1[n-1]-prefix1[i],prefix2[i-1]);

                ans = min(ans,maxi);
            }
        }

        return ans;
    }
};