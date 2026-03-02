class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n);

        // Step 1: count trailing zeros
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                count++;
            }
            trailing[i] = count;
        }

        int swaps = 0;

        // Step 2: greedy placement
        for (int i = 0; i < n; i++) {
            int needed = n - i - 1;
            int j = i;

            // Find suitable row
            while (j < n && trailing[j] < needed)
                j++;

            if (j == n) return -1;

            // Bubble up
            while (j > i) {
                swap(trailing[j], trailing[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};