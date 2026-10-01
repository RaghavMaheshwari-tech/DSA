class Solution {
public:
    int maxDepth(string s) {
        int d=0;
        int ans = 0;

        for(char c:s){
            if(c=='('){
                d++;
            }
            else if(c==')'){
                d--;
            }

            ans = max(ans,d);
        }

        return ans;
    }
};