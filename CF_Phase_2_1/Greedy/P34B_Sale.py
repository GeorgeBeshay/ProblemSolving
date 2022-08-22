# Problem Link:         https://codeforces.com/problemset/problem/34/B
# Problem Status:       Accepted.
# ------------------------ SEPARATOR ------------------------
# ------------------------ SEPARATOR ------------------------
from typing import List
# ------------------------ SEPARATOR ------------------------


def TheAmazingFunction(Array: list[int], Q):
    Array.sort()
    Counter = 0
    Answer = 0
    while Q > 0 > Array[Counter] and Counter < len(Array):
        Answer += Array[Counter]
        Counter += 1
        Q -= 1
    return abs(Answer)


# ------------------------ SEPARATOR ------------------------
N, M = list(map(int, input().split()))
Arr: list[int] = list(map(int, input().split()))
print(TheAmazingFunction(Arr, M))
# ------------------------ SEPARATOR ------------------------
