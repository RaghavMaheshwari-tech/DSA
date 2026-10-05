class Solution {
public:
    
    vector<int> KMP(string &s, string &temp){
        int n = temp.size();
        int m = s.size();

        vector<int>lps(n,0);
        vector<int>ans;

        int pre=0,curr=1;
        while(curr<n){
            if(temp[pre]==temp[curr]){
                lps[curr] = pre+1;
                pre++;
                curr++;
            }
            else{
                if(pre==0){
                    lps[curr] = 0;
                    curr++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }

        //searching

        int first=0,sec=0;
        while(first<m){
            if(s[first]==temp[sec]){
                first++;
                sec++;
            }
            else{
                if(sec==0){
                    first++;
                }
                else{
                    sec = lps[sec-1];
                }
            }


            if(sec==n){
                ans.push_back(first-sec);
                sec = lps[sec-1];
            }
        }

        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();

        vector<int>temp1 = KMP(s,a);
        vector<int>temp2 = KMP(s,b);
        vector<int>ans;

        for(int i=0;i<temp1.size();i++){
            int target = temp1[i];
            auto x = lower_bound(temp2.begin(),temp2.end(),target-k);
            if(x!=temp2.end() && *x<=target+k) ans.push_back(temp1[i]);
        }

        return ans;
    }
};