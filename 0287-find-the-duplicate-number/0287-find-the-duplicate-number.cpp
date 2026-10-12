class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0,fast=0;
        int x = slow;

        slow=nums[slow];
        fast=nums[nums[fast]];
        

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        while(x!=slow){
            x=nums[x];
            slow=nums[slow];
        }

        return x;

    }
};