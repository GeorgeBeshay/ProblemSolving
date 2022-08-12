# Problem Link:     https://codeforces.com/problemset/problem/939/B
# Problem Status:   Accepted.
# --------------------------- SEPARATOR ---------------------------
# Scanning Input
Reader = input()
N = int(Reader.split()[0])
K = int(Reader.split()[1])
Reader = input()
TextArr = Reader.split()
A = {}
B = []
C = []
i = 1
for X in TextArr:
    C.append(int(X))
    B.append(N % int(X))
    A.update({N % int(X): i})
    i += 1
# --------------------------- SEPARATOR ---------------------------
B.sort()
print(f"{A.get(B[0])} {N // C[A.get(B[0])-1]}")
# --------------------------- SEPARATOR ---------------------------
