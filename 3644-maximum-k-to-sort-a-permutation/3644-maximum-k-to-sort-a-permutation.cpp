class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int x=-1;

        for(int i=0;i<n;i++){
            if(i!=nums[i]){
                if(x==-1) x=nums[i];
                else x = x&nums[i];
            }
        }

        return (x!=-1)? x:0;
    }
};