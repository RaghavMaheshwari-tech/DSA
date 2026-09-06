class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;

        int n = path.size();
        string temp;

        for(int i=0;i<=n;i++){

            if(path[i]=='/' || i==n){
                if(temp=="." || temp=="") {

                }

                else if(temp==".."){
                    if(st.size()>0){
                        st.pop_back();
                    }
                }

                else st.push_back(temp);

                temp = "";
            }

            else temp.push_back(path[i]);
        }
        
        string ans;


        for(auto word: st){
            ans+= '/'+word;
        }

        if(ans.size()==0) return "/";
        else return ans;
    }
};