class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string>stock;
        for(auto supply:supplies) stock.insert(supply);

        unordered_map<string,vector<int>>mp;
        vector<int>indeg(n,0);

        for(int i=0;i<n;i++){
            for(string& thing : ingredients[i]){
                if(stock.count(thing)==0){
                    mp[thing].push_back(i);
                    indeg[i]++;
                }
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }

        vector<string>ans;

        while(!q.empty()){
            int idx = q.front();
            q.pop();

            ans.push_back(recipes[idx]);

            for(int i=0;i<mp[recipes[idx]].size();i++){
                indeg[mp[recipes[idx]][i]]--;
                if(indeg[mp[recipes[idx]][i]]==0) q.push(mp[recipes[idx]][i]);
            }
        }

        return ans;
    }
};