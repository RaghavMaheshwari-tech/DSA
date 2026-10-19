class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int i=0;
        int start=0,end=nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]>=target){
                i=mid;
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }

        while(i<nums.size() && nums[i]==target){
            ans.push_back(i);
            i++;
        }

        return ans;
    }
};