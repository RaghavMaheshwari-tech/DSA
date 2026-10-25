class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int x=0;//max value ka index
        int val=height[0];//max value
        for(int i=1;i<n;i++){
            if(val<height[i]){
                x=i;
                val = height[i];
            }
        }
//2,6,3,4,4
        int y=height[0];
        int ans = 0;

        for(int i=1;i<x;i++){
            int mini = min(y,val);
            if(mini-height[i]>0) ans+=(mini-height[i]);

            if(y<height[i]) y=height[i];
        }

        y=height[n-1];

        for(int i=n-2;i>x;i--){
            int mini = min(y,val);
            if(mini-height[i]>0) ans+=(mini-height[i]);
            if(y<height[i]) y=height[i];
        }

        return ans;
    }
};