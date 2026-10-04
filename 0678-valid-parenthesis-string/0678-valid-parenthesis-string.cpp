class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();
        vector<int>fut(n+2,0);
        fut[1] = 1;

        for(int idx=n-1;idx>=0;idx--){
            vector<int>curr(n+2,0);
            for(int count=n;count>0;count--){

                if(s[idx]=='('){
                    curr[count] = fut[count+1];
                }
                else if(s[idx]==')'){
                    curr[count] = fut[count-1];
                }
                else{
                    curr[count] = fut[count+1] || fut[count-1] || fut[count];
                }
            }
            fut = curr;
        }

        return fut[1];
    }
};