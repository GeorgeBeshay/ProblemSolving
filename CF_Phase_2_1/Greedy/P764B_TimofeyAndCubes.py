# Problem Link:     https://codeforces.com/contest/764/problem/B
# Problem Status:   Accepted.
# ----------------------- SEPARATOR -----------------------
# Function Definition
def solvingFunctionA(Arr):
    for i in range(0, int(len(Arr)/2), 2):
        Temp = Arr[i]
        Arr[i] = Arr[len(Arr)-i-1]
        Arr[len(Arr)-i-1] = Temp
    return Arr


# ----------------------- SEPARATOR -----------------------
N = int(input())
Reader = input().split()
A = []
for i in range(N):
    A.append(int(Reader[i]))
A = solvingFunctionA(A)
for i in range(N):
    print(f"{A[i]} ", end="")
# ----------------------- SEPARATOR -----------------------
