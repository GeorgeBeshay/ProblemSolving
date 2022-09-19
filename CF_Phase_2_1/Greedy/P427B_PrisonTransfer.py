# Problem Link:         https://codeforces.com/problemset/problem/427/B
# Problem Status:       Accepted.
# ----------- Separator -----------
def TheAmazingFunction(Arr: list, T_, C_):
    B = Arr.copy()
    temp = -C_
    Ans = 0
    Arr.reverse()
    for i in range(0, len(Arr)):
        if Arr[i] > T_:
            B[i] = -C_
            temp = -C_
        else:
            if temp == 0:
                B[i] = 0
            else:
                B[i] = temp + 1
                temp += 1
    for H in B:
        if H == 0:
            Ans += 1
    return Ans


# ----------- Separator -----------
N, T, C = list(map(int, input().split()))
A = list(map(int, input().split()))
print(TheAmazingFunction(A, T, C))
# ----------- Separator -----------
