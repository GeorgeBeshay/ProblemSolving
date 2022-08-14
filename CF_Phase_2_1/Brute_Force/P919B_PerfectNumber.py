# Problem Link:     https://codeforces.com/problemset/problem/919/B
# Problem Status:   Accepted.
# -------------------------- SEPARATOR --------------------------
def checkPerfectionism(A):
    A = str(A)
    Sum = 0
    for X in A:
        Sum += int(X)
    if Sum == 10:
        return True
    else:
        return False


# -------------------------- SEPARATOR --------------------------
# Scanning The Input
N = int(input())
Order = 1
Number = 19
while Order < N:
    Number += 9
    if checkPerfectionism(Number):
        Order += 1
# -------------------------- SEPARATOR --------------------------
print(Number)
# -------------------------- SEPARATOR --------------------------
