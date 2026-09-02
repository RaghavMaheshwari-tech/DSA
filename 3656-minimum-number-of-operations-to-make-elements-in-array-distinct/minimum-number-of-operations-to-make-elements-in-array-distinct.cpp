class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int x= n;
        unordered_map<int,int>mp;
        unordered_set<int>st;
        int start=0,end=0;

        for(int val : nums){
            mp[val]++;
            st.insert(val);
        }

        if(n==st.size()) return 0;
        if(n<=3) return 1;

        int count=0;

        while(start<n-3){
            count++;
            mp[nums[start]]--;
            mp[nums[start+1]]--;
            mp[nums[start+2]]--;

            if(mp[nums[start]]==0) st.erase(nums[start]);
            if(mp[nums[start+1]]==0) st.erase(nums[start+1]);
            if(mp[nums[start+2]]==0) st.erase(nums[start+2]);

            x-=3;

            if(st.size()==x) return count;
            start+=3;
        }


        return (x==st.size())? count:count+1;




    }
};