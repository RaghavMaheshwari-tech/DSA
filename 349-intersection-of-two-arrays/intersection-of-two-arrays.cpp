class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
        for(auto val:nums1) st.insert(val);
        vector<int>ans;

        for(auto val:nums2){
            if(st.count(val)){
                ans.push_back(val);
                st.erase(val);
            } 
        }

        return ans;
    }
};