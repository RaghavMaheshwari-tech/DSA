class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(auto &[key,val]:mp){
            pq.push({val,key});
        }

        while(k>0 && !pq.empty()){
            auto &[freq,number] = pq.top();
            if(freq>k) break;

            k-=freq;
            pq.pop();
        }

        return pq.size();
    }
};