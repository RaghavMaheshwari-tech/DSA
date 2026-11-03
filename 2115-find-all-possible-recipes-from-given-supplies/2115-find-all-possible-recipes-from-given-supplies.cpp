class Solution {
public:
    vector<string>ans;



    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string>stock,order;
        for(auto supply:supplies) stock.insert(supply);

        vector<bool>seen(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                bool found=1;
                if(seen[j]==0){
                    for(int k=0;k<ingredients[j].size();k++){
                        if(stock.count(ingredients[j][k])==0){
                            found=0;
                            break;
                        }
                    }
                    if(found){
                        stock.insert(recipes[j]);
                        seen[j]=1;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            if(seen[i]) ans.push_back(recipes[i]);
        }

        return ans;
    }
};