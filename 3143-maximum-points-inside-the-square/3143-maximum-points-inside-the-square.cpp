class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {

        //o(n) way
        //find the second minimum distance of the repeated characters , then go with the loop and take the character which have the distance less than that..

        
        int n = points.size();
        vector<pair<int,int>>arr;//max abs(cordinate), char
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            int a = abs(points[i][0]);
            int b = abs(points[i][1]);
            arr.push_back({max(a,b),s[i]});
            mp[max(a,b)]++;
        }

        sort(arr.begin(),arr.end());

        vector<int>seen(26,0);
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            char c = arr[i].second;
            int dis = arr[i].first;

            if(seen[c-'a']==1){
                if(st.find(dis)!=st.end()) st.erase(dis);

                break;
            }

            st.insert(dis);
            seen[c-'a']=1;

        }

        int count =0;
        for(auto i:st){
            count+=mp[i];
        }

        return count;
    }
};