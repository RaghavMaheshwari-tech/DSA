class Solution {
public:
    string solve(string start , string end, string operation){
        int ans;
        if(operation=="+"){
            ans = stoi(start)+stoi(end);
        }
        else if(operation=="-"){
            ans = stoi(start)-stoi(end);
        }
        else if(operation=="*"){
            ans = stoi(start)*stoi(end);
        }
        else{
            ans = stoi(start)/stoi(end);
        }

        return to_string(ans);
    }

    int evalRPN(vector<string>& tokens) {
        stack<string>st;

        for(auto val : tokens){
            if(val == "+" || val == "-" ||val == "*" ||val == "/"){
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();

                st.push(solve(b,a,val));
            }
            else st.push(val);
        }

        return stoi(st.top());
    }
};