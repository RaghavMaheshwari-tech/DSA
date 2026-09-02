class Solution {
public:
    int partitionString(string s) {
        int count=0;
        unordered_set<char>st;

        for(auto c:s){
            if(st.find(c)!=st.end()){
                count++;
                st.clear();
            }
            st.insert(c);
        }


        return count+1;
    }
};