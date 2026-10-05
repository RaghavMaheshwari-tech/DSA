class Solution {
public:
    typedef long long ll;
    bool check(ll stone, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost){
        for(int i=0;i<composition.size();i++){

            ll total=0;
            for(int j=0;j<composition[0].size();j++){
                if(stock[j]<stone*composition[i][j])
                    total += (stone*composition[i][j]-stock[j])*cost[j];
            }

            if(total<=budget) return 1;
        }

        return 0;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        
        ll start=0;
        ll end=1e8+budget/n;//cost of each stone is 1
        ll ans=0;

        while(start<=end){
            ll mid = start+(end-start)/2;

            if(check(mid,budget,composition,stock,cost)){
                ans = mid;
                start=mid+1;
            }
            else end=mid-1;
        }

        return ans;

    }
};