class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        string temp;
        int n = path.size();

        for(int i=0;i<=n;i++){

            if(i==n || path[i]=='/'){

                if(temp=="" || temp=="."){

                }

                else if(temp==".."){
                    if(!st.empty()) st.pop_back();
                } 

                else st.push_back(temp);

                temp = "";
            }
            else temp.push_back(path[i]);
        }

        string ans;

        for(auto word:st){
            ans += "/"+ word;
        }

        if(ans.size()==0) return "/";

        return ans;
    }
};