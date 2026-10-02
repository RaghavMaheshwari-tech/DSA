class Solution {
public:
    vector<string>ans;
    void solve(int left, int right, string temp, int n){
        if(left==n && right==n){
            ans.push_back(temp);
            return;
        }

        if(left<n){
            temp.push_back('(');
            solve(left+1,right,temp,n);
            temp.pop_back();
        }

        if(left>right && right<n){
            temp.push_back(')');
            solve(left,right+1,temp,n);
            temp.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(0,0,"",n);
        return ans;
    }
};