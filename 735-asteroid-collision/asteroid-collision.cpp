class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;

        for(int val : asteroids){
            if(st.empty() || val>=0) st.push(val);

            else{
                
                while(!st.empty() && st.top()>=0 && st.top()<abs(val) ){
                    st.pop();
                }

                if(st.empty() || st.top()<0) st.push(val);

                else if(st.top()==abs(val)) st.pop();
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