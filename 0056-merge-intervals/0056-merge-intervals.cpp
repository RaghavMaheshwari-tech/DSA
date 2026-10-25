class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        stack<pair<int,int>>st;
        for(int i=0;i<intervals.size();i++){
            if(!st.empty() && intervals[i][0]<=st.top().second){
                st.top().second = max(st.top().second,intervals[i][1]);
            }
            else st.push({intervals[i][0],intervals[i][1]});
        }

        
        int n = st.size();
        vector<vector<int>>ans;
        while(!st.empty()){
            auto &[p,q] = st.top();
            st.pop();
            ans.push_back({p,q});
        }


        return ans;
    }
};