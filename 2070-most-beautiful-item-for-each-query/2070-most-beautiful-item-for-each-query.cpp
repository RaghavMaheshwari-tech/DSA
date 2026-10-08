class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        unordered_set<int>st;
        for(vector<int> val:items){
            st.insert(val[0]);
        }

        vector<int>price;
        for(int val:st){
            price.push_back(val);
        }
        sort(price.begin(),price.end());

        map<int,int>mp;

        for(vector<int> val:items){
            if(mp.find(val[0])==mp.end()){
                mp[val[0]] = val[1];
            }
            else mp[val[0]] = max(mp[val[0]],val[1]);
        }

        for(int i=1;i<price.size();i++){
            mp[price[i]] = max(mp[price[i]],mp[price[i-1]]);
        }

        int n = queries.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int target=queries[i];
            int start=0,end=price.size()-1;
            int x=-1;

            while(start<=end){
                int mid=start+(end-start)/2;

                if(price[mid]<=target){
                    x=mid;
                    start=mid+1;
                }
                else end = mid-1;
            }

            if(x!=-1){
                ans[i] = mp[price[x]];
            }
            else ans[i]=0;

        }

        return ans;

        


    }
};