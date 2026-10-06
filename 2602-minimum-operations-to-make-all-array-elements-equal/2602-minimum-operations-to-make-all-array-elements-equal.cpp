class Solution {
public:
    typedef long long ll;
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin(),nums.end());

        vector<ll>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];

        

        vector<ll>ans(m);


        for(int i=0;i<m;i++){
            int target=queries[i];
            int x=-1;

            int start=0,end=n-1;

            while(start<=end){
                int mid = start+(end-start)/2;

                if(nums[mid]<=target){
                    x=mid;
                    start=mid+1;
                }
                else end=mid-1;
            }

            ll val;

            if(x!=-1){
                val = 1LL*target*(x+1)-prefix[x] + (prefix[n-1]-prefix[x])- 1LL*(n-x-1)*target;
            }  
            else val =  prefix[n-1] - 1LL*n*target;

            
            ans[i]=val;
        }

        return ans;
    }
};