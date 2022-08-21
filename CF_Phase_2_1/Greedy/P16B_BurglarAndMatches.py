# Problem Link:     https://codeforces.com/problemset/problem/16/B
# Problem Status:   Accepted.
# ------------------------------- SEPARATOR -------------------------------
# IDEA:
#   Given That the no. of matches in any matchbox is in range [1, 10]
#   So by creating a 2D Array storing all the match boxes in them depending on the number of
#   matches inside them
#   Finally iterate over the 2D Array backward and keep adding the wanted number of match boxes, until its done.
# ------------------------------- SEPARATOR -------------------------------
Reader = input().split()
N = int(Reader[0])
M = int(Reader[1])
Answer = 0
Table = []
# ------------------------------- SEPARATOR -------------------------------
for i in range(10):
    Table.append([])
for i in range(M):
    Reader = input().split()
    Table[int(Reader[1])-1].append(int(Reader[0]))
# ------------------------------- SEPARATOR -------------------------------
c1 = 9
c2 = 0
while N > 0 and c1 >= 0:
    if c2 >= len(Table[c1]):
        c1 -= 1
        c2 = 0
    else:
        if Table[c1][c2] <= N:
            Answer += Table[c1][c2] * (c1+1)
        else:
            Answer += N * (c1+1)
        N -= Table[c1][c2]
        c2 += 1
# ------------------------------- SEPARATOR -------------------------------
print(Answer)
# ------------------------------- SEPARATOR -------------------------------
