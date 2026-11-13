class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans= *max_element(nums.begin(),nums.end());

        long long sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0) sum=0;
            ans= max(1LL*ans,sum);
        }
        for(int i=0;i<n;i++){
            nums[i]*=-1;
        }

        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0) sum=0;
            ans=max(1LL*ans,sum);
        }

        return (int)ans;
    }
};