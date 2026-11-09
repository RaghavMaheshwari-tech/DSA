class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,stack<int>>mp;

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push(nums[i][j]);
            }
        }

        vector<int>ans;

        for(auto [key,st]:mp){

            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};