# Problem Link:         https://codeforces.com/problemset/problem/486/A
# Problem Status:       Accepted
# ------------------- Separator -------------------
import math
# ------------------- Separator -------------------


def TheAmazingFunction(X):
    Ans = 0
    Ans += math.floor(X / 2)
    if X % 2 != 0:
        Ans -= X
    return Ans


# ------------------- Separator -------------------
N = int(input())
print(TheAmazingFunction(N))
# ------------------- Separator -------------------
