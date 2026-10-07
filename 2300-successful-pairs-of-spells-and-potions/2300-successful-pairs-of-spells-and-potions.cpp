class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int>ans;

        for(int val:spells){

            int start=0,end=m-1;
            int idx=-1;
            while(start<=end){
                int mid= start+(end-start)/2;

                if(1LL*potions[mid]*val>=success){
                    idx=mid;
                    end=mid-1;
                }
                else start=mid+1;
            }

            if(idx==-1) ans.push_back(0);
            else ans.push_back(m-idx);
        }

        return ans;
    }
};