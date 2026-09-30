class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.size();
        vector<int>ans;
        int depth=0;

        for(auto c:s){
            if(c=='('){
                depth++;
                if(depth%2==0) ans.push_back(0);
                else ans.push_back(1);
            }
            else if(c==')'){
                if(depth%2==0) ans.push_back(0);
                else ans.push_back(1);

                depth--;
            }
        }

        return ans;
    }
};