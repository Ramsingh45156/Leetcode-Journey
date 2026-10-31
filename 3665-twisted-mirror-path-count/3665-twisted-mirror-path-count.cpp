class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        vector<int> down(grid[0].size());  // ways to enter each cell from above
        down[0] = 1;
        for (auto& row : grid) {
            int right = 0;  // ways to enter the current cell from the left
            for (int j = 0; j < row.size(); j++) {
                int above = down[j], merged = right + above;  // an empty cell merges them
                merged -= merged >= mod ? mod : 0;  // both are below mod: one subtraction replaces %
                down[j] = row[j] ? right : merged;  // a mirror swaps the flows
                right = row[j] ? above : merged;
            }
        }
        return down.back();
    }
};