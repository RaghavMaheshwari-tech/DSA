class Solution {
public:
    static bool comp(const vector<string> &vec1, const vector<string> &vec2){
        int t1 = stoi(vec1[1]);
        int t2 = stoi(vec2[1]);

        if(t1==t2){
            return vec1[0]>vec2[0];
        }

        return t1<t2;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        vector<int>ans(n,0);
        unordered_map<int,int>mp;

        sort(events.begin(),events.end(), comp);

        for(int i=0;i<events.size();i++){
            if(events[i][0]=="OFFLINE"){
                int x = stoi(events[i][2]);
                mp[x] = stoi(events[i][1]);
            }
            else{
                if(events[i][2]=="ALL"){
                    for(int j=0;j<n;j++) ans[j]++;
                }
                else if(events[i][2]=="HERE"){
                    int time = stoi(events[i][1]);

                    for(int j=0;j<n;j++){
                        if(mp.find(j)!=mp.end()){
                            if(mp[j]+60<=time){
                                mp.erase(j);
                                ans[j]++;
                            }
                        }
                        else ans[j]++;
                    }
                }
                else{

                    vector<string>ids;
                    stringstream ss(events[i][2]);

                    string token;
                    while(ss>>token){
                        ids.push_back(token);
                    }

                    for(string id:ids){
                        ans[stoi(id.substr(2))]++;
                    }
                }
            }
        }

        return ans;
    }
};