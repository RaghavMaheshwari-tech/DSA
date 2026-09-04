class Solution {
public:
    bool valid(char c){
        return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || 
                c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    string sortVowels(string s) {
        int n = s.size();
        string temp;

        for(char c : s){
            if(valid(c)){
                temp.push_back(c);
            }
        }

        sort(temp.begin(),temp.end());

        int first=0;

        for(int i=0;i<n;i++){
            if(valid(s[i])){
                s[i] = temp[first];
                first++;
            }
        }


        return s;
    }
};