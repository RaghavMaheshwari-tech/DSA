class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_set<int>st;
        for(int val:banned) st.insert(val);


        long long sum=0;
        int count=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                if(sum+i>maxSum) return count;
                else{
                    sum+=i;
                    count++;
                }
                
            }

        }

        return count;
    }
};