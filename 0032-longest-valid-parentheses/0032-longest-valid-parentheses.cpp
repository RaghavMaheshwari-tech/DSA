class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int len=0;
        
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') l++;
            else r++;
        }
        if(l==n || r==n) return 0;
        
        for(int i=0;i<n;i++){
            int left=0,right=0;
            for(int j=i;j<n;j++){
                if(s[j]=='(') left++;
                else right++;

                if(right>left) break;

                if(left==right){
                    len = max(len,left*2);
                }
            }
        }

        return len;
    }
};