# Problem Link:        https://codeforces.com/problemset/problem/591/B
# Problem Status:      Accepted.
# --------------------------- SEPARATOR ---------------------------
def TheAmazingFunction(Title: str, Arr: list):
    Title = list(Title)
    Table = dict()
    Letters = []
    for T in range(97, 97+26):
        Table.update({chr(T): T-97})
        Letters.append(chr(T))
    for U in Arr:
        c1 = U[0]
        c2 = U[1]
        i1 = Table.get(c1)
        i2 = Table.get(c2)
        Table.update({c1: i2})
        Table.update({c2: i1})
    for K in Table:
        Letters[Table.get(K)] = K
    for L in range(len(Title)):
        Title[L] = Letters[ord(Title[L]) - 97]
    Title = str(Title).replace(", ", "").replace("'", "").removesuffix("]").removeprefix("[")
    return Title


# --------------------------- SEPARATOR ---------------------------
N, M = list(map(int, input().split()))
Name = input()
A = []
for i in range(M):
    A.append([])
    A[-1] = input().split()
print(TheAmazingFunction(Name, A))
# --------------------------- SEPARATOR ---------------------------
