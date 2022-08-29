# Problem Link:     https://codeforces.com/problemset/problem/680/B
# Problem Status:   Accepted.
# -------------------- SEPARATOR --------------------
def TheAmazingFunction(Arr: list, A):
    Answer = 0
    i = A - 1
    j = A - 1
    while i >= 0 or j < len(Arr):
        if i == j:
            if Arr[i] == 1:
                Answer += 1
        else:
            if i >= 0 and j < len(Arr):
                if Arr[i] + Arr[j] == 2:
                    Answer += 2
            else:
                if i >= 0:
                    Answer += Arr[i]
                else:
                    Answer += Arr[j]
        i -= 1
        j += 1
    return Answer


# -------------------- SEPARATOR --------------------
N, A_ = list(map(int, input().split()))
Arr_ = list(map(int, input().split()))
print(TheAmazingFunction(Arr_, A_))
# -------------------- SEPARATOR --------------------
