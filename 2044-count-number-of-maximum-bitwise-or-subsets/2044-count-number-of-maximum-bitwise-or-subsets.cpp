class Solution {
public:
    int maxOR = 0;
    int count = 0;

    void dfs(vector<int>& nums, int idx, int currOR) {
        if (idx == nums.size()) {
            if (currOR == maxOR)
                count++;
            return;
        }
        dfs(nums, idx + 1, currOR | nums[idx]);
        dfs(nums, idx + 1, currOR);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int x : nums)
            maxOR |= x;
        dfs(nums, 0, 0);
        return count;
    }
};