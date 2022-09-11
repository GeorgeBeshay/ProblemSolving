# Problem Link:             https://codeforces.com/problemset/problem/890/B
# Problem Status:           Accepted.
# ---------------- Separator ----------------
def TheAmazingFunction(Arr: list, K):
    LastVisitTable = dict()
    temp = 999999
    Ans = -1
    for i in range(K):
        LastVisitTable.update({Arr[i]: i})
    for Key, Value in LastVisitTable.items():
        if Value < temp:
            temp = Value
            Ans = Key
        else:
            continue
    return Ans


# ---------------- Separator ----------------
N = int(input())
A = list(map(int, input().split()))
print(TheAmazingFunction(A, N))
# ---------------- Separator ----------------
