class Solution {
public:
    typedef long long ll;
    ll check(int x, int &h, vector<int>&piles){
        int n = piles.size();
        ll ans=0;

        for(int val:piles){
            ll y = (val%x==0)? val/x:val/x+1;
            ans+=y;
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int end = *max_element(piles.begin(),piles.end());
        int start=1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(check(mid,h,piles)<=h){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return ans;
    }
};