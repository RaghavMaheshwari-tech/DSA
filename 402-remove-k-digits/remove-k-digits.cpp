class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        stack<char>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        string temp;

        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        while(!temp.empty() && temp.back()=='0'){
            temp.pop_back();
        }

        if(temp.size()==0) return "0";

        reverse(temp.begin(),temp.end());

        return temp;
    }
};