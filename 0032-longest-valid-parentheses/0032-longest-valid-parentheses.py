class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)

        if n < 2:
            return 0

        st = []
        dp = [0] * n

        ans = 0

        for i in range(n):

            if s[i] == '(':
                st.append(i)

            else:  # s[i] == ')'

                if st:
                    x = st[-1]

                    dp[i] = i - x + 1

                    if x >= 1:
                        dp[i] += dp[x - 1]

                    st.pop()

                ans = max(ans, dp[i])

        return ans