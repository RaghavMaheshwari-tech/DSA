class Solution {
public:
    bool find(int &idx, vector<int>&r, int bricks, int ladders){
        int n = r.size();

        vector<int>temp;
        for(int i=1;i<=idx;i++){
            if(r[i]>0) temp.push_back(r[i]);
        }

        sort(temp.begin(),temp.end());

        int count=0;
        int y= temp.size();

        for(int i=0;i<max(y-ladders,0);i++){
            if(bricks-temp[i]>=0){
                bricks-=temp[i];
                count++;
            }
            else return 0;
        }

        return 1;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        vector<int>required(n,0);
        for(int i=1;i<n;i++){
            if(heights[i]>heights[i-1]){
                required[i] = heights[i]-heights[i-1];
            }
        }

        int start=0,end=n-1;

        int ans=0;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(find(mid,required,bricks,ladders)){
                ans = mid;
                start=mid+1;
            }
            else end= mid-1;
        }

        return ans;
    }
};