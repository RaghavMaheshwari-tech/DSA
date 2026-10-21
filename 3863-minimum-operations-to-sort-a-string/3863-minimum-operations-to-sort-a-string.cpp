class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n==1) return 0;
        if(n==2){
            if(s[0]<=s[1]) return 0;
            else return -1;
        }

        string temp = s;
        sort(temp.begin(),temp.end());
        if(temp==s) return 0;
        else if(temp[0]==s[0] || temp[n-1]==s[n-1]) return 1;
        else{
            string arr1 = s;
            sort(arr1.begin(),arr1.begin()+n-1);
            sort(arr1.begin()+1,arr1.end());
            if(arr1==temp) return 2;

            string arr2 = s;
            sort(arr2.begin()+1,arr2.end());
            sort(arr2.begin(),arr2.begin()+n-1);
            if(arr2==temp) return 2;

            else return 3;
        }
    }
};