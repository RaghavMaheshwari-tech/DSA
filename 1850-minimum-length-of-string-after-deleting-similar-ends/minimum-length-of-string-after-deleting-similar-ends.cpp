class Solution {
public:
    int minimumLength(string s) {
        int start=0,end=s.size()-1;


        while(start<end){
            if(s[start]==s[end]){

                start++;
                while(start<end && s[start]==s[start-1]){
                    start++; 
                }

                end--;
                while(start<end && s[end]==s[end+1]){
                    end--;
                }
            }

            else return end - start+1;
        }
        return end - start+1;
    }
};