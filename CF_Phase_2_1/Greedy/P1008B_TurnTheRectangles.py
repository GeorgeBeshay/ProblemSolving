# Problem Link:     https://codeforces.com/problemset/problem/1008/B
# Problem Status:   Accepted.
# -------------- Separator --------------
def getMin(X_, Y_):
    if X_ <= Y_:
        return X_
    else:
        return Y_


def getMax(X_, Y_):
    if X_ >= Y_:
        return X_
    else:
        return Y_


# -------------- Separator --------------
N = int(input())
flag = True
temp = -1
while N:
    N -= 1
    X, Y = list(map(int, input().split()))
    if temp == -1:
        temp = getMax(X, Y)
    else:
        if temp >= getMax(X, Y) and temp >= getMin(X, Y):
            temp = getMax(X, Y)
        elif temp >= getMin(X, Y):
            temp = getMin(X, Y)
        else:
            print("NO")
            flag = False
            break
if flag:
    print("YES")
# -------------- Separator --------------
