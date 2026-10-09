class Solution {
public:
    int find(int &target, vector<int>&p, int &m){
        int n = p.size();

        int count=1;
        int prev=0;
        for(int i=1;i<n;i++){
            if(p[i]-p[prev]>=target){
                count++;
                prev=i;
            }

            if(count>=m) return 1;
        }

        return 0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int start = 1;
        int end = position[n-1]-position[0];
        int ans = 0;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(find(mid,position,m)){
                ans = mid;
                start=mid+1;
            }
            else end=mid-1;
        }

        return ans;
    }
};