class Solution {
public:
    int ans = 0;

    void dfs(vector<int>& nums, int index, int xr) {
        if (index == nums.size()) {
            ans += xr;
            return;
        }
        // Include current element
        dfs(nums, index + 1, xr ^ nums[index]);
        // Exclude current element
        dfs(nums, index + 1, xr);
    }
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0, 0);
        return ans;
    }
};