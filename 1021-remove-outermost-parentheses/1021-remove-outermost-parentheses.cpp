class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=0;
        int n = s.size();

        vector<int>visited(n,1);

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
                if(depth==1) visited[i]=0;
            }
            
            else{
                depth--;
                if(depth==0) visited[i]=0;
            }
        }

        string ans;
        for(int i=0;i<n;i++){
            if(visited[i]==1) ans.push_back(s[i]);
        }

        return ans;


    }
};