class Solution {
public:
    void solve(int i, int n , int k, vector<vector<int>>&ans, vector<int> &temp){

        if(i>n){
            if(temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }

        //not take it
        solve(i+1,n,k,ans,temp);
        //take it
        temp.push_back(i);
        solve(i+1,n,k,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,n,k,ans,temp);
        return ans;
    }
};