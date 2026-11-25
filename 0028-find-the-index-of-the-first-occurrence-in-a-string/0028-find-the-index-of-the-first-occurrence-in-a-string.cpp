
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if(m > n) return -1;

        vector<int> last(256, -1);

        // Build Bad Character Table
        for(int i = 0; i < m; i++) {
            last[(unsigned char)needle[i]] = i;
        }

        int s = 0;

        while(s <= n - m) {
            int j = m - 1;

            // Compare from right to left
            while(j >= 0 && needle[j] == haystack[s + j]) {
                j--;
            }

            // Pattern found
            if(j < 0) {
                return s;
            }

            // Bad Character Rule
            int bad = (unsigned char)haystack[s + j];

            s += max(1, j - last[bad]);
        }

        return -1;
    }
};
