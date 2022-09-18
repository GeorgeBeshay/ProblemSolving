# Problem Link:         https://codeforces.com/problemset/746/A
# Problem Status:       Accepted.
# ------------ Separator ------------
import math


def TheAmazingFunction(A, B, C):
    return (min(A, math.floor(B / 2), math.floor(C / 4))) * 7


# ------------ Separator ------------
X = int(input())
Y = int(input())
Z = int(input())
print(TheAmazingFunction(X, Y, Z))
# ------------ Separator ------------
