class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        
        // Map to store frequency of each row
        map<vector<int>, int> rowCount;
        for(int i = 0; i < n; i++) {
            rowCount[grid[i]]++; 
        }

        // Check each column
        for(int j = 0; j < n; j++) {
            vector<int> col;
            for(int i = 0; i < n; i++) {
                col.push_back(grid[i][j]); // Extracting column elements
            }
            // Agar yeh column kisi row jaisa hai, toh uski frequency add kar do
            ans += rowCount[col];
        }

        return ans;
    }
};