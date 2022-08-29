# Problem Link:     https://codeforces.com/problemset/problem/222/B
# Problem Status:   TIME LIMIT EXCEEDED ON TEST CASE NUMBER 12.
# --------------------------- SEPARATOR ---------------------------
def TheAmazingFunction(A: list, Q: list):
    # RS = dict()          # Row Swapping
    CS = dict()
    # RS2 = dict()
    CS2 = dict()
    # ---------- Separator ----------
    # for i in range(1, len(A)+1):
    #     RS.update({i: i})
    #     RS2.update({i: i})
    for i in range(1, len(A[0])+1):
        CS.update({i: i})
        CS2.update({i: i})
    # ---------- Separator ----------
    for i in range(len(Q)):
        # print(RS)
        # print(RS2)
        # print(CS)
        # print(CS2)
        if Q[i][0] == 'g':
            # print(A[RS2.get(Q[i][1])-1][CS2.get(Q[i][2])-1])
            print(A[Q[i][1]-1][CS2.get(Q[i][2]) - 1])
        elif Q[i][0] == 'r':
            X = A[Q[i][1]-1].copy()
            A[Q[i][1]-1] = A[Q[i][2]-1].copy()
            A[Q[i][2]-1] = X.copy()
            # RS.update({RS2.get(Q[i][1]): Q[i][2]})
            # T1 = RS2.get(Q[i][1])
            # RS.update({RS2.get(Q[i][2]): Q[i][1]})
            # T2 = RS2.get(Q[i][2])
            # RS2.update({Q[i][2]: T1})
            # RS2.update({Q[i][1]: T2})
        elif Q[i][0] == 'c':
            T1 = CS2.get(Q[i][1])
            T2 = CS2.get(Q[i][2])
            CS.update({T1: Q[i][2]})
            CS.update({T2: Q[i][1]})
            CS2.update({Q[i][2]: T1})
            CS2.update({Q[i][1]: T2})
    # ---------- Separator ----------


# --------------------------- SEPARATOR ---------------------------
N, M, K = list(map(int, input().split()))
Arr = []
Queries = []
for j in range(N):
    Arr.append(list(map(int, input().split())))
for j in range(K):
    Queries.append(list(input().split()))
    Queries[-1][1], Queries[-1][2] = int(Queries[-1][1]), int(Queries[-1][2])
TheAmazingFunction(Arr, Queries)
# --------------------------- SEPARATOR ---------------------------
