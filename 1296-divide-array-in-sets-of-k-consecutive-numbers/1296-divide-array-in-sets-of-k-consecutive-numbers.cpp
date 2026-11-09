class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        int n = nums.size();
        if(n%k!=0) return 0;

        multiset<int>st;
        for(int val:nums) st.insert(val);
        

        while(!st.empty()){
            int x = *st.begin();
            int y=1;

            while(y<=k){
                if(st.find(x)==st.end()) return 0;

                auto it = st.find(x);
                st.erase(it);
                x++;
                y++;
            }
        }

        return 1;
    }
};