# Problem Link:     https://codeforces.com/problemset/problem/255/B
# Problem Status:   Accepted.
# ---------------------- SEPARATOR ----------------------
def TheAmazingFunction(S: str):
    X_count = 0
    Y_count = 0
    for i in S:
        if i == 'x':
            X_count += 1
        else:
            Y_count += 1
    if X_count >= Y_count:
        S = "x"*(X_count-Y_count)
    else:
        S = "y" * (Y_count - X_count)
    return S


# ---------------------- SEPARATOR ----------------------
S_ = input()
print(TheAmazingFunction(S_))
# ---------------------- SEPARATOR ----------------------
