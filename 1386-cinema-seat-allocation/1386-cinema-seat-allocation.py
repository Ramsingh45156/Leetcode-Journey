class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        rows = {}
        for r, s in reservedSeats:
            if r not in rows:
                rows[r] = set()
            rows[r].add(s)
        ans = 2 * n
        for seats in rows.values():
            families = 0
            if all(s not in seats for s in range(2, 6)):
                families += 1

            if all(s not in seats for s in range(6, 10)):
                families += 1

            if families == 0:
                if all(s not in seats for s in range(4, 8)):
                    families = 1

            ans -= 2
            ans += families
        return ans