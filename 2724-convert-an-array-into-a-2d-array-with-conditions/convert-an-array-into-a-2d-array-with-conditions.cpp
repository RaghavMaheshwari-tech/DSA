class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;

        unordered_map<int,int>mp;
        for(int val:nums) mp[val]++;
        int x=0;

        while(x!=nums.size()){
            vector<int>temp;
            for(auto it=mp.begin();it!=mp.end();it++){
                if(it->second>0){
                    temp.push_back(it->first);
                    mp[it->first]--;
                    x++;
                }
            }
            
            ans.push_back(temp);
        }
        
        

        return ans;
    }
};