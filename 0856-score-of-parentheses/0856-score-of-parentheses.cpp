class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;

        for(auto c :s){
            if(st.empty() || c=='('){
                st.push(-1);

            }
            else{
                int x = 0;
                while(st.top()!=-1){
                    x+=st.top();
                    st.pop();
                }
                st.pop();
                if(x==0) st.push(1);
                else{
                    x=2*x;
                    st.push(x);
                }
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};