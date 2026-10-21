class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // 1. Check if already sorted (0 operations)
        bool is_sorted = true;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] > s[i + 1]) {
                is_sorted = false;
                break;
            }
        }
        if (is_sorted) return 0;
        
        // 2. Unsortable edge case for length 2 (-1 operations)
        if (n == 2) return -1;
        
        // Find the global minimum and maximum characters
        char mn = s[0];
        char mx = s[0];
        for (char c : s) {
            if (c < mn) mn = c;
            if (c > mx) mx = c;
        }
        
        // 3. Check if 1 operation is enough
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // 4. Check if min or max exists anywhere in the middle (2 operations)
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        
        // 5. Otherwise, both are trapped at opposite ends (3 operations)
        return 3;
    }
};
