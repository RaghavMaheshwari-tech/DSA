class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st,st2;
        for(auto val:nums1) st.insert(val);
        vector<int>ans;

        for(auto val:nums2){
            if(st.count(val)) st2.insert(val);
        }

        for(auto val:st2) ans.push_back(val);

        return ans;
    }
};