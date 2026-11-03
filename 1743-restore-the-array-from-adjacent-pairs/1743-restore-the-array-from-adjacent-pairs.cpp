class Solution {
public:
    vector<int>ans;
    unordered_set<int>st;
    void solve(int &x, unordered_map<int,vector<int>>&mp){

        ans.push_back(x);
        st.insert(x);

        for(auto y:mp[x]){
            if(st.count(y)) continue;
            else(solve(y,mp));
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            int a = adjacentPairs[i][0];
            int b = adjacentPairs[i][1];

            mp[a].push_back(b);
            mp[b].push_back(a);
        }

        int x =-1;
        for(auto [key,vec]: mp){
            if(vec.size()==1){
                x=key;
                break;
            }
        }

        solve(x,mp);

        return ans;

        

    }
};