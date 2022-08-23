# Problem Link:     https://codeforces.com/problemset/problem/701/B
# Problem Status:   Accepted.
# --------------------------- SEPARATOR ---------------------------
# IDEA:
#   By Observing a 5 x 5 Map, you will notice that there are mainly
#   4 Cases when placing a rook:
#       - Common Row, - Common Column, - Common Row and Column, - No Commons
#   on each case a different mathematical operations should be applied
#   on the variable "Answer"
#   case 1: subtract (N-1) from the Answer and the number of rows already taken
#   case 2: subtract (N-1) from the Answer and the number of cols already taken
#   case 3: do nothing
#   case 4: subtract 2N-1 from the answer and the number of rows and cols already taken
# --------------------------- SEPARATOR ---------------------------
def TheAmazingFunction(N, M):
    RowsTaken = dict()
    ColsTaken = dict()
    Answer = N**2
    while M > 0:
        M -= 1
        R, C = list(map(int, input().split()))
        if RowsTaken.get(R) is not None and ColsTaken.get(C) is not None:
            print(Answer, end=" ")
        elif RowsTaken.get(R) is None and ColsTaken.get(C) is not None:
            Answer -= N-len(ColsTaken)
            RowsTaken.update({R: 1})
            print(Answer, end=" ")
        elif RowsTaken.get(R) is not None and ColsTaken.get(C) is None:
            Answer -= N-len(RowsTaken)
            ColsTaken.update({C: 1})
            print(Answer, end=" ")
        else:
            Answer -= (2 * N) - 1 - len(ColsTaken) - len(RowsTaken)
            RowsTaken.update({R: 1})
            ColsTaken.update({C: 1})
            print(Answer, end=" ")


# --------------------------- SEPARATOR ---------------------------
N_, M_ = list(map(int, input().split()))
TheAmazingFunction(N_, M_)
# --------------------------- SEPARATOR ---------------------------
