class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> state(k, 0);

        for (int value : nums) {
            int rem = value % k;
            vector<long long> nextState(k, 0);

            for (int r = 0; r < k; r++) {
                if (state[r] > 0) {
                    int newRem = (r * rem) % k;
                    nextState[newRem] += state[r];
                    result[newRem] += state[r];
                }
            }

            nextState[rem] += 1;
            result[rem] += 1;

            state = nextState;
        }

        return result;
    }
};
