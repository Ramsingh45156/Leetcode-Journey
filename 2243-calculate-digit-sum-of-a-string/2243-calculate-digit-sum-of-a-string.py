class Solution:
    def digitSum(self, s: str, k: int) -> str:
        ans  = s 

        while len(ans) > k :
            next_ans = ""
            curr = -99
            for i in range(len(ans)) :
                if curr == -99 :
                    curr = int(ans[i])
                else:
                    curr += int(ans[i])
                if (i+1)%k == 0 :
                    next_ans += str(curr)
                    # print(curr)
                    curr = -99
            if curr != -99 :
                next_ans += str(curr)
             

            ans = next_ans
            print(ans)
        return ans
                

        