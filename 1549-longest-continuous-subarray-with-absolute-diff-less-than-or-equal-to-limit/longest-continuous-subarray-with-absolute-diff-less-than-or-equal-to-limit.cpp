class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int>st;

        int ans = 0;
        int end=0,start=0;
        while(end<n){
            st.insert(nums[end]);

            while(abs(*prev(st.end())-*st.begin())>limit){
                st.erase(st.find(nums[start]));
                start++;
            }

            ans = max(ans,end-start+1);

            end++;
        }

        return ans;
    }
};