class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        priority_queue<pair<int,char>>pq;

        for(char c:s){
            mp[c]++;
        }

        string ans;

        for(auto [key,val]:mp){
            pq.push({val,key});
        }

        while(!pq.empty()){
            auto [val, c] = pq.top();
            pq.pop();

            while(val--) ans+=c;
        }

        return ans;
    }
};