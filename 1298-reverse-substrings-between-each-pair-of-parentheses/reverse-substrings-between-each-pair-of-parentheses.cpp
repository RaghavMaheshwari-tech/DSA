class Solution {
public:
    string reverseParentheses(string s) {
        int n =s.size();
        vector<int>arr(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                arr[st.top()] = i;
                arr[i] = st.top();
                st.pop();
            }
        }

        string ans;
        int dir=1;//l->r
        int i=0;

        while(i<n){
            if(s[i]=='(' || s[i]==')'){
                i = arr[i];
                dir = -dir;
            }
            else ans.push_back(s[i]);

            i+=dir;
        }

        return ans;




    }
};