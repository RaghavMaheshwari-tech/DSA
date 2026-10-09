class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        // Min-heap keeps track of the largest climbs where we want to use ladders
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < n - 1; i++) {
            int climb = heights[i + 1] - heights[i];

            if (climb > 0) {
                min_heap.push(climb);

                // If climbs exceed available ladders, use bricks for the smallest climb
                if (min_heap.size() > ladders) {
                    bricks -= min_heap.top();
                    min_heap.pop();
                }

                // If we run out of bricks, we cannot step onto building i + 1
                if (bricks < 0) {
                    return i;
                }
            }
        }

        return n - 1;
    }
};
