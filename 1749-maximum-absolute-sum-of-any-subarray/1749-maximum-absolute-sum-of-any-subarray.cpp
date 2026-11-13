class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        long long sum=0;


        //ya toh bilkul minimum find krlo ya bilkul maximum..

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0) sum=0;
            ans= max(1LL*ans,sum);
        }


        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>0) sum=0;
            ans=max(1LL*ans,abs(sum));
        }

        return (int)ans;
    }
};