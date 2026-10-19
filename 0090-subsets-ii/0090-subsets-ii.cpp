class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    void solve(int idx, int n, vector<int>&temp, vector<int>&nums){
        if(idx==n){
            st.insert(temp);
            return;
        }

        solve(idx+1,n,temp,nums);
        temp.push_back(nums[idx]);
        solve(idx+1,n,temp,nums);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(0,n,temp,nums);

        for(auto val:st){
            ans.push_back(val);
        }

        return ans;
        
    }
};