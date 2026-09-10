class Solution {
public:
    typedef long long ll;
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int>st;
        ll ans = 0;
        int start=0,end=0;

        while(end<n){
            st.insert(nums[end]);

            while(*prev(st.end()) - *st.begin() >2){
                
                st.erase(st.find(nums[start]));
                start++;
            }

            ans += (end-start+1);
            end++;
        }


        return ans;
    }
};