# Problem Link:         https://codeforces.com/problemset/problem/339/B
# Problem Status:       Accepted.
# -------------------------- SEPARATOR --------------------------
def TheAmazingFunction(N: int, A: list):
    Ans = 0
    CurrentHouse = 1
    for i in A:
        if i >= CurrentHouse:
            Ans += i - CurrentHouse
        else:
            Ans += N - CurrentHouse + 1
            Ans += i - 1
        CurrentHouse = i
    return Ans


# -------------------------- SEPARATOR --------------------------
N_, M_ = list(map(int, input().split()))
A_ = list(map(int, input().split()))
print(TheAmazingFunction(N_, A_))
# -------------------------- SEPARATOR --------------------------
