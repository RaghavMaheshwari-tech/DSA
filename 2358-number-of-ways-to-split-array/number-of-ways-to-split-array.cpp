class Solution {
public:
    typedef long long ll;
    int waysToSplitArray(vector<int>& nums) {
        int n= nums.size();

        vector<ll>prefix(n),suffix(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];


        for(int i=1;i<n;i++) prefix[i]=nums[i]+prefix[i-1];
        for(int i=n-2;i>=0;i--) suffix[i]=nums[i]+suffix[i+1];

        int count=0;

        for(int i=0;i<n-1;i++){
            if(prefix[i]>=suffix[i+1]) count++;
        }

        return count;


    }
};