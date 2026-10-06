class Solution {
public:
    typedef long long ll;

    bool check(ll &target, int &cars, vector<int> &ranks){
        ll ans=0;

        for(int i=0;i<ranks.size();i++){
            ans+=sqrt((target/ranks[i]));
        }

        if(ans>=cars) return 1;
        return 0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int mini=*min_element(ranks.begin(),ranks.end());
        int maxi=*max_element(ranks.begin(),ranks.end());

        ll start=mini;
        ll end=1LL*maxi*cars*cars;
        ll ans=end;

        while(start<=end){
            ll mid = start+(end-start)/2;

            if(check(mid,cars,ranks)){
                ans = mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return ans;
    }
};