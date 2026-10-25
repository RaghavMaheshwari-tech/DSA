class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int i=0;

        while(i<n-2){

            int target=nums[i];
            int start=i+1,end=n-1;
            while(start<end){
                if(-target==nums[start]+nums[end]){
                    ans.push_back({target,nums[start],nums[end]});

                    while(start<end && nums[start]==nums[start+1]) start++;
                    while(start<end && nums[end]==nums[end-1]) end--;

                    start++;
                    end--;
                }
                else if(-target > nums[start]+nums[end]) start++;
                else end--;
            }
            
            while(i<n-2 && nums[i]==nums[i+1]) i++;
            i++;
        }

        return ans;

    }
};