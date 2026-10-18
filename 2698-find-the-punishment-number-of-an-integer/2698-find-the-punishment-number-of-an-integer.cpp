class Solution {
public:
    bool solve(int idx, string &temp,int x,int sum){

        if(idx==temp.size()){
            if(sum==x) return 1;
            else return 0;
        }

        int y=0;
        
        for(int i=idx;i<temp.size();i++){
            y = y*10+(temp[i]-'0');
            sum+=y;
            if(solve(i+1,temp,x,sum)) return 1;
            sum-=y;
        }

        return 0;

    }
    int punishmentNumber(int n) {

        int ans=0;

        for(int i=1;i<=n;i++){
            int sum = i*i;
            string temp = to_string(sum);
            if(solve(0,temp,i,0)) ans+=(i*i);
        }

        return ans;
    }
};