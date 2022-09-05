# Problem Link:         https://codeforces.com/problemset/problem/554/B
# Problem Status:       Accepted.
# ---------------------------- SEPARATOR ----------------------------
def TheAmazingFunction(Grid: list):
    Table = dict()
    MaxNumOfCommonRows = 0
    for line in Grid:
        if Table.get(line) is None:
            Table.update({line: 1})
        else:
            Table.update({line: Table.get(line)+1})
        if Table.get(line) > MaxNumOfCommonRows:
            MaxNumOfCommonRows = Table.get(line)
    return MaxNumOfCommonRows


# ---------------------------- SEPARATOR ----------------------------
N = int(input())
A = []
for i in range(N):
    A.append(input())
print(TheAmazingFunction(A))
# ---------------------------- SEPARATOR ----------------------------
