class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), i=0;
        int result=0;
        int count=0;

        while(i<n){
            if(s[i]=='(') {
                count++;
                i++;
            }
            else{
                if(count>0) count--;
                else result+=1;

                if(i+1<n && s[i+1]==')') i+=2;
                else{
                    result+=1;
                    i++;
                }
            }
        }

        return result + count*2;
    }
};