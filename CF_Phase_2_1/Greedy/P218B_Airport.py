# Problem Link:         https://codeforces.com/problemset/problem/218/B
# Problem Status:       Accepted.
# ----------------------- Separator -----------------------
def TheAmazingFunction(Arr: list, K: int):
    Arr.sort()
    ArrCopy = Arr.copy()
    KCopy = K
    Min = 0
    Max = 0
    while K > 0:
        K -= 1
        Min += Arr[0]
        Arr[0] -= 1
        if Arr[0] == 0:
            Arr.remove(Arr[0])
        Arr.sort()
    while KCopy > 0:
        KCopy -= 1
        Max += ArrCopy[-1]
        ArrCopy[-1] -= 1
        if ArrCopy[-1] == 0:
            ArrCopy.remove(ArrCopy[-1])
        ArrCopy.sort()
    return str(Max) + " " + str(Min)


# ----------------------- Separator -----------------------
N, M = list(map(int, input().split()))
A = list(map(int, input().split()))
print(TheAmazingFunction(A, N))
# ----------------------- Separator -----------------------
