class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int dec=1;
        int inc=1;
        int len=1;
        int n = nums.size();
        for(int i=1;i<n;i++){
             if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
             }
             else if(nums[i]<nums[i-1]){
                inc=1;
                dec++;
             }
             else{
                inc=1;
                dec=1;
             }
            len = max({len,dec,inc});
        }

        return len;
    }
};