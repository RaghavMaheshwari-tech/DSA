class Solution {
public:
    bool solve(int idx, string temp,int x,int sum){

        if(idx==temp.size()){
            if(sum==x) return 1;
            else return 0;
        }

        string curr;
        
        for(int i=idx;i<temp.size();i++){
            curr+=temp[i];
            int y = stoi(curr);
            sum+=y;
            if(solve(i+1,temp,x,sum)) return 1;
            sum-=y;
        }

        return 0;

    }
    int punishmentNumber(int n) {
        vector<bool>arr(1001,0);

        for(int i=1;i<=1000;i++){
            int sum = i*i;
            string temp = to_string(sum);
            if(solve(0,temp,i,0)) arr[i]=1;
        }

        int ans=0;

        for(int i=1;i<=n;i++){
            if(arr[i]) ans+=(i*i);
        }

        return ans;
    }
};