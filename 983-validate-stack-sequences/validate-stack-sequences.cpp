class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n = pushed.size(),first=0,sec=0;;

        while(first<n){
            while(!st.empty() && st.top()==popped[sec]){
                st.pop();
                sec++;
            }
            st.push(pushed[first]);
            first++;
        }

        while(!st.empty() && st.top()==popped[sec]){
            st.pop();
            sec++;
        }


        return sec==n;
    }
};