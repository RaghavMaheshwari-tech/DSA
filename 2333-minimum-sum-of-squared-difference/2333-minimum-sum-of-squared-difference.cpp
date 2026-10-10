class Solution {
public:
    typedef long long ll;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        ll k = 1LL*k1+k2;
        vector<ll>diff(1e5+1,0);
        for(int i=0;i<n;i++){
            diff[abs(nums1[i]-nums2[i])]++;
        }

        for(int i=1e5;i>=1;i--){
            if(diff[i]==0) continue;
            ll x = min(1LL*diff[i],k);
            diff[i-1]+=x;
            diff[i]-=x;

            k-=x;
            if(k==0) break;
        }

        ll ans=0;

        for(int i=1e5;i>=1;i--){
            if(diff[i]==0) continue;
            else ans+=(diff[i]*i*i);
        }

        return ans;


    }
};