class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i, int sum, vector<int>&candidates, int &target, vector<int>&temp){

        if(i==candidates.size()){
            if(sum==target) ans.push_back(temp);
            return;
        }


        solve(i+1,sum,candidates,target,temp);
        if(sum+candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(i,sum+candidates[i],candidates,target,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();
        vector<int>temp;

        solve(0,0,candidates,target,temp);
        return ans;
        
    }
};