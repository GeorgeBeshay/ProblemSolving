# Problem Link:         https://codeforces.com/problemset/problem/106/B
# Problem Status:       Accepted.
# ----------------------------------- SEPARATOR -----------------------------------
# IDEA:
#   Iterate over each laptop, whenever a laptop outdated found skip it, else add the laptop to a new array
#   Iterate over the new array, choose the cheapest one.
# ----------------------------------- SEPARATOR -----------------------------------
# Functions Definition:
def SolverA(Array):
    NOD = [Array[0]]    # Not Out Dated
    NOD[0].append(1)
    for E in range(1, len(Array)):
        X = Array[E]
        Flag1 = True
        Flag2 = False
        for H in NOD:
            if X[0] > H[0] and X[1] > H[1] and X[2] > H[2]:
                Flag2 = True
            else:
                Flag2 = False
                break
        if Flag2:
            NOD.clear()
            NOD.append(X)
            NOD[0].append(E+1)
            continue
        for H in NOD:
            if X[0] < H[0] and X[1] < H[1] and X[2] < H[2]:
                Flag1 = False
                break
            else:
                continue
        if Flag1:
            NOD.append(X)
            NOD[-1].append(E+1)
    for X in NOD:
        Flag1 = True
        for H in NOD:
            if X[0] < H[0] and X[1] < H[1] and X[2] < H[2]:
                Flag1 = False
                break
        if not Flag1:
            X[-1] = -1
    MinCost = -10
    Answer = 0
    for Y in NOD:
        if MinCost == -10:
            if Y[4] != -1:
                MinCost = Y[3]
                Answer = Y[4]
        elif Y[3] < MinCost and Y[4] != -1:
            MinCost = Y[3]
            Answer = Y[4]
    return Answer


# ----------------------------------- SEPARATOR -----------------------------------
# Scanning Input:
N = int(input())
A = []
for i in range(N):
    A.append([])
    Reader = input().split()
    for j in range(4):
        A[i].append(int(Reader[j]))
print(SolverA(A))
# ----------------------------------- SEPARATOR -----------------------------------
