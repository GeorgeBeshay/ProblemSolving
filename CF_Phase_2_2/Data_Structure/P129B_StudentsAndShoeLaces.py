# Problem Link:     https://codeforces.com/problemset/problem/129/B
# Problem Status:
# -------------------------------------- SEPARATOR --------------------------------------
def TheAmazingFunction(Arr: list, K):
    Ans = 0
    if K == 0:
        return Ans
    # -----------------------------------------
    while not CheckArr(Arr):
        copyA = copyArr(Arr)
        for Q in range(len(Arr)):
            if len(Arr[Q]) == 1:
                Arr[Q][0] = -1
            else:
                Temp = 0
                for o in range(len(Arr[Q])):
                    if Arr[Q][o] != -1:
                        Temp += 1
                if Temp == 0:
                    Arr[Q] = [-1]
        # -----------------------------------------
        for H in range(len(Arr)):
            if len(Arr[H]) > 1:
                for Z in range(len(Arr[H])):
                    if len(Arr[Arr[H][Z]]) == 1:
                        if Arr[Arr[H][Z]][0] == -1:
                            Arr[H][Z] = -1
        # -----------------------------------------
        for S in range(len(Arr)):
            if len(Arr[S]) > 1:
                Temp = []
                for P in range(len(Arr[S])):
                    if Arr[S][P] != -1:
                        Temp.append(Arr[S][P])
                if len(Temp) > 0:
                    Arr[S] = Temp
                else:
                    Arr[S] = [-1]
        # -----------------------------------------
        if CheckEquivalence(copyA, Arr):
            break
        Ans += 1
    return Ans
# -------------------------------------- SEPARATOR --------------------------------------


def copyArr(Arr: list):
    Arr_ = []
    for i in range(len(Arr)):
        Arr_.append([])
        for j in range(len(Arr[i])):
            Arr_[-1].append(Arr[i][j])
    return Arr_
# -------------------------------------- SEPARATOR --------------------------------------


def CheckArr(Arr: list):
    Flag = True
    Count = 0
    for T in range(len(Arr)):
        if type(Arr[T]) is list:
            for E in range(len(Arr[T])):
                if Arr[T][E] != -1:
                    Count += 1
    if Count > 1:
        Flag = False
    # print(Count)
    return Flag
# -------------------------------------- SEPARATOR --------------------------------------


def CheckEquivalence(Arr1: list, Arr2: list):
    Flag = True
    if len(Arr1) != len(Arr2):
        Flag = False
    else:
        for i in range(len(Arr1)):
            if len(Arr1[i]) != len(Arr2[i]):
                Flag = False
                break
            for j in range(len(Arr1[i])):
                if Arr1[i][j] != Arr2[i][j]:
                    Flag = False
                    break
            if not Flag:
                break
    return Flag
# -------------------------------------- SEPARATOR --------------------------------------


N, M = list(map(int, input().split()))
A = []
for i in range(N):
    A.append([])
for i in range(M):
    X, Y = list(map(int, input().split()))
    A[X-1].append(Y-1)
    A[Y-1].append(X-1)
# -------------------------------------- SEPARATOR --------------------------------------
print(TheAmazingFunction(A, M))
# -------------------------------------- SEPARATOR --------------------------------------
