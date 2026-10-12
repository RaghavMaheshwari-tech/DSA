class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        
        int n = nums.size();
        vector<long long>arr(n);

        int x=n+1;
        for(int i=0;i<n;i++){
            arr[i]=1LL*(nums[i]-1)*x;//0-based 
        }

        for(int i=0;i<n;i++){
            int idx = arr[i]/x;
            arr[idx]++;
        }

        for(int i=0;i<n;i++){
            if(arr[i]%x>=2) return i+1;
        }

        return -1;


    }
};