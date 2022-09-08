# Problem Link:         https://codeforces.com/problemset/problem/137/B
# Problem Status:       Accepted.
# ----------------------------- Separator -----------------------------
def TheAmazingFunction(S: list):
    table = dict()
    Ans = 0
    for i in S:
        table.update({i: 1})
    for i in range(1, len(S)+1):
        if table.get(i) is None:
            Ans += 1
    return Ans


# ----------------------------- Separator -----------------------------
length = int(input())
S_ = list(map(int, input().split()))
print(TheAmazingFunction(S_))
# ----------------------------- Separator -----------------------------
