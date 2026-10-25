class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        long long ans =0;

        while(start<end){
            int len=end-start;
            int mini = min(height[start],height[end]);
            ans = max(ans,1LL*mini*len);

            if(height[start]<height[end]) start++;
            else end--;
        }

        return ans;
    }
};