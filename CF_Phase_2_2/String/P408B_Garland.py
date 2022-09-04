# Problem Link:     https://codeforces.com/problemset/problem/408/B
# Problem Status:   Accepted.
# ----------------------- SEPARATOR -----------------------
def TheAmazingFunction(L1: str, L2: str):
    # ------------- Variables -------------
    Table = dict()
    Needed = dict()
    Ans = 0
    # ------------- Separator -------------
    for i in range(97, 97+26):
        Table.update({chr(i): 0})
        Needed.update({chr(i): 0})
    # ------------- Separator -------------
    for C in L1:
        Table.update({C: Table.get(C)+1})
    # ------------- Separator -------------
    for C in L2:
        Needed.update({C: Needed.get(C) + 1})
    # ------------- Separator -------------
    for X in Needed:
        if Needed.get(X) == 0:
            continue
        elif Table.get(X) == 0:
            return -1
        else:
            if Table.get(X) < Needed.get(X):
                Ans += Table.get(X)
            else:
                Ans += Needed.get(X)
    return Ans


# ----------------------- SEPARATOR -----------------------
LineOne = input()
LineTwo = input()
print(TheAmazingFunction(LineOne, LineTwo))
# ----------------------- SEPARATOR -----------------------
