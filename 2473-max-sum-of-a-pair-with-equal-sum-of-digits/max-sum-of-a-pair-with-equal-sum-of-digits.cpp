class Solution {
public:

    int digitSUM(int x){

        int ans=0;
        while(x){
            int rem = x%10;
            ans+=rem;
            x/=10;
        }

        return ans;
    }

    int maximumSum(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,priority_queue<int, vector<int>, greater<int>>>mp;

        for(int i=0;i<n;i++){
            int x = digitSUM(nums[i]);
            mp[x].push(nums[i]);
            if(mp[x].size()>2) mp[x].pop();
        }

        int ans = -1;

        for(auto [sum,q]:mp){

            int m = q.size();
            
            if(m==2){
                int x = q.top();
                q.pop();
                int b = q.top();

                ans = max(ans,x+b);
            }
        }

        return ans;
    }
};