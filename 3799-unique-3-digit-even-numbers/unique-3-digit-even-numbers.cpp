class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int>mp;//digit,no. of times

        for(int i=0;i<digits.size();i++) mp[digits[i]]++;

        int count = 0;

        for(int i=100;i<=999;i++){
            if(i%2!=0) continue;

            unordered_map<int,int>arr;
            bool valid = 1;
            
            int x = i;
            while(x!=0){
                int rem =x%10;
                arr[rem]++;
                x/=10;
            }

            for(auto [key,value] : arr){
                if(!mp[key] || mp[key]<value){
                    valid = 0;
                    break;
                }
            }

            if(valid) count++;
        }

        return count;
    }
};