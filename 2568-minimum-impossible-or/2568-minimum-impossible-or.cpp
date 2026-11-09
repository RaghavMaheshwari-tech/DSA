class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int val:nums) mp[val]++;

        long long val=1;
        while(1){
            if(mp.find(val)==mp.end()) return (int)val;

            val*=2;
        }

        return val;

    }
};