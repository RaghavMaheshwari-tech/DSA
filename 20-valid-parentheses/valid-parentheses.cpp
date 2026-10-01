class Solution {
public:
    bool isValid(string s) {

        stack<char>st;
        
        for(char c:s){
            if(st.empty() || c=='(' || c=='[' || c=='{') st.push(c);
            else if(c==')' && st.top()=='(') st.pop();
            else if(c=='}' && st.top()=='{') st.pop();
            else if(c==']' && st.top()=='[') st.pop();
            else return 0;
        }

        return st.empty()==1;
    }
};