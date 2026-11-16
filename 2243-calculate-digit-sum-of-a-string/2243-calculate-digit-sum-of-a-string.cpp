class Solution {
public:
    string digitSum(string s, int k) {
        string temp=s;

        while(temp.size()>k){
            int cnt=0;
            string new_s;
            int sum=0;
            for(int i=0;i<temp.size();i++){
                sum+= (temp[i]-'0');
                cnt++;
                if(cnt==k || i==temp.size()-1){
                    new_s+=(to_string(sum));
                    sum=0;
                    cnt=0;
                }
            }

            temp=new_s;

        }

        return temp;
    }
};