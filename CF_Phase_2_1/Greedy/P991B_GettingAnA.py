# Problem Link:     https://codeforces.com/problemset/problem/991/B
# Problem Status:   Accepted.
# ------------------------- SEPARATOR -------------------------
def TheAmazingFunction(Arr: list):
    Sum = 0
    Needed = 0
    Answer = 0
    for i in range(len(Arr)):
        Sum += Arr[i]
    Needed = 4.5 * len(Arr) - Sum
    Arr.sort()
    for i in range(len(Arr)):
        if Needed <= 0:
            break
        if Arr[i] < 5:
            Needed -= 5-Arr[i]
            Answer += 1
    return Answer


# ------------------------- SEPARATOR -------------------------
# Scanning Input
N = int(input())
A = list(map(int, input().split()))
# ------------------------- SEPARATOR -------------------------
print(TheAmazingFunction(A))
# ------------------------- SEPARATOR -------------------------
