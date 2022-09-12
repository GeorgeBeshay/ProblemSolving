# Problem Link:         https://codeforces.com/problemset/problem/182/B
# Problem Status:       Accepted.
# ----------------- SEPARATOR -----------------
def TheAmazingFunction(D: int, A: list) -> int:
    Ans = 0
    for X in A[0: -1]:
        Ans += (D - X)
    return Ans


# ----------------- SEPARATOR -----------------
D_ = int(input())
N_ = int(input())
A_ = list(map(int, input().split()))
print(TheAmazingFunction(D_, A_))
# ----------------- SEPARATOR -----------------
