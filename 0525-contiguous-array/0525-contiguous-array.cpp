class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;

        int n = nums.size();
        int ans=0;
        mp[0]=-1;
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt--;
            }
            else cnt++;


            if(mp.find(cnt)!=mp.end()){
                ans = max(ans,i-mp[cnt]);
            }
            else mp[cnt] = i;
        }

        return ans;
    }
};