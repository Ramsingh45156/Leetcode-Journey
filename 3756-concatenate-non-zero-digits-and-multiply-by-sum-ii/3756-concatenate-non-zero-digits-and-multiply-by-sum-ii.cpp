class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefixNum(n + 1, 0);
        vector<int> prefixSum(n + 1, 0);
        vector<int> prefixCnt(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            prefixSum[i + 1] = prefixSum[i] + d;
            prefixCnt[i + 1] = prefixCnt[i];

            prefixNum[i + 1] = prefixNum[i];

            if (d != 0) {
                prefixCnt[i + 1]++;
                prefixNum[i + 1] = (prefixNum[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int cnt = prefixCnt[r + 1] - prefixCnt[l];
            int sum = prefixSum[r + 1] - prefixSum[l];

            long long x =
                (prefixNum[r + 1] -
                 prefixNum[l] * pow10[cnt] % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};