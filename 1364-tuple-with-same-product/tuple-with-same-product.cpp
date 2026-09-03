class Solution {
public:
    typedef long long ll;

    // ll solve(int a, int b){
    //     if (b==0) return 1;

    //     ll half = solve(a,b/2);
    //     ll result = half*half;

    //     if(b%2!=0) return a*result;
    //     return result;
    // }

    int tupleSameProduct(vector<int>& nums) {
        unordered_map<ll,vector<pair<int,int>>>mp;
        int n = nums.size();

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]].push_back({i,j});
            }
        }

        int ans=0;

        for(auto [val,temp]:mp){

            int x = temp.size();

            if(x>1){
                ans+=(8*((x*(x-1))/2));
            }
        }

        return ans;
    }
};