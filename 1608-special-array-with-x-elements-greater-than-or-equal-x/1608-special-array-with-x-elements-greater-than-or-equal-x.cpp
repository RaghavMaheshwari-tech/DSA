class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int>arr(n+1,0);
        int j=0;
        for(int i=0;i<n+1;i++){
            while(j<n && nums[j]<i) j++;

            // arr[i] = n-j;
            
            if(i == (n-j) ) return i;

            if(j>=n) break;
        }

        return -1;
    }
};