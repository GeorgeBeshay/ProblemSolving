# Problem Link:         https://codeforces.com/problemset/problem/102/B
# Problem Status:       Accepted.
# --------------- Separator ---------------
def TheAmazingFunction(N):
    ans = 0
    while len(str(N)) > 1:
        temp = 0
        for i in str(N):
            temp += int(i)
        N = temp
        ans += 1
    return ans


# --------------- Separator ---------------
N_ = input()
print(TheAmazingFunction(N_))
# --------------- Separator ---------------
