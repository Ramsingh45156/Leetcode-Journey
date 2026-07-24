class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        const int MAXX = 2048;

        vector<vector<bool>>dp(4,vector<bool>(MAXX,false));
        dp[0][0] = true;

        unordered_set<int> ans;

        // Single elements are always possible
        for (int x : nums)
            ans.insert(x);

        for (int val : nums) {
            for (int cnt = 2;cnt >= 0;cnt--) {
                for (int xr=0;xr < MAXX;xr++) {
                    if (dp[cnt][xr]) {
                        dp[cnt + 1][xr^val] = true;
                    }
                }
            }
        }
        for (int xr = 0;xr < MAXX;xr++) {
            if (dp[3][xr])
                ans.insert(xr);
        }
        return ans.size();
    }
};