class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int n, int k, vector<int>&temp){
        if(i>n){
            if(temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }

        solve(i+1,n,k,temp);
        temp.push_back(i);
        solve(i+1,n,k,temp);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(1,n,k,temp);
        return ans;
    }
};