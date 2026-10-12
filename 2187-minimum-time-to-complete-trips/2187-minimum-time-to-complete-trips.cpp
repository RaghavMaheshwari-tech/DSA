class Solution {
public:
typedef long long ll ;

    bool check(ll mid,  vector<int>& time, int totalTrips){
        int n = time.size();
        ll ans =0;
        for(int i=0;i<n;i++){
            ll val = mid/time[i];
            ans+=val;
        };

        return ans>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        ll start =*min_element(time.begin(),time.end());
        ll end = 1LL*(*max_element(time.begin(),time.end()))*totalTrips;

        ll ans=0;

        while(start<=end){
            ll mid = start+(end-start)/2;

            if(check(mid,time,totalTrips)){
                ans =mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return ans;

    }
};