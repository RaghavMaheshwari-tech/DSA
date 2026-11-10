class Solution {
public:
    typedef long long ll;
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<ll>prefix(n,0);
        prefix[0]=nums[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
            ll left=0;
            if(i>0) left = nums[i]*i-(prefix[i-1]);
            ll right = (prefix[n-1]-prefix[i])-nums[i]*(n-i-1);

            ans[i] = (int)left+(int)right;
        }

        return ans;


    }
};