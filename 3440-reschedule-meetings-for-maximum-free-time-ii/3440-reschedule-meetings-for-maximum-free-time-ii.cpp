class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>free;
        free.push_back(startTime[0]-0);

        for(int i=1;i<n;i++){
            free.push_back(startTime[i]-endTime[i-1]);
        }
        free.push_back(eventTime-endTime[n-1]);

        int ans = *max_element(free.begin(),free.end());

        int m = free.size();

        vector<int>prefix_max(m,0);
        vector<int>suffix_max(m,0);

        for(int i=1;i<m;i++){
            prefix_max[i] = max(prefix_max[i-1],free[i-1]);
        }
        for(int i=m-2;i>=0;i--){
            suffix_max[i] = max(suffix_max[i+1],free[i+1]);
        }


        for(int i=1;i<=m-1;i++){
            
            int mysize = endTime[i-1]-startTime[i-1];

            //case 1;

            if(mysize<=prefix_max[i-1] || mysize<=suffix_max[i]){
                ans = max(ans,free[i]+free[i-1]+mysize);
            }

            //case 2:

            else ans = max(ans,free[i]+free[i-1]);
        }

        return ans;
    }
};