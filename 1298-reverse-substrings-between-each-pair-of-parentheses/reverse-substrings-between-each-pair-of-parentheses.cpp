class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int>st1;

        for(int i=0;i<n;i++){
            if(s[i]=='(') st1.push(i);
            else if(s[i]==')'){
                reverse(s.begin()+st1.top(),s.begin()+i+1);
                st1.pop();
            }
        }

        string ans ;

        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]==')') continue;

            ans.push_back(s[i]);
            
        }

        return ans;
    }
};