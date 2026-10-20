class Solution {
public:
    vector<vector<int>>ans;
    void find(int i, int sum, int target, vector<int>&cand, vector<int>&temp){

        if(sum>target) return;
        if(i==cand.size()){
            if(sum==target) ans.push_back(temp);
            return;
        }

        temp.push_back(cand[i]);
        find(i+1,sum+cand[i],target,cand,temp);
        temp.pop_back();

        int curr = cand[i];
        while(i+1<cand.size() && cand[i+1]==curr) i++;
        find(i+1,sum,target,cand,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        find(0,0,target,candidates,temp);
        return ans;
    }
};