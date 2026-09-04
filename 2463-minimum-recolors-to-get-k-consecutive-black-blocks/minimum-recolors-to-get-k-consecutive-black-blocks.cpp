class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int count=0;
        
        for(int i=0;i<k;i++){
            if(blocks[i]=='B') count++;
        }

        int maxB = count;

        for(int i=k;i<n;i++){
            if(blocks[i]=='B') count++;
            if(blocks[i-k]=='B') count--;

            maxB = max(maxB,count);
        }

        return k-maxB;
    }
};