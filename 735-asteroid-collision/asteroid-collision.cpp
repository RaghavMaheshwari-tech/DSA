class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;

        for(int val : asteroids){
            if(st.empty() || val>=0) st.push(val);

            else{
                bool flag=1;
                while(!st.empty() && st.top()>=0){
                    if(abs(val)<st.top()) {
                        flag=0;
                        break;
                    }
                    else if(abs(val)==st.top()){
                        flag=0;
                        st.pop();
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(flag) st.push(val);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};