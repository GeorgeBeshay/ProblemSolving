# Problem Link:     https://codeforces.com/problemset/problem/998/B
# Problem Status:   Accepted.
# ------------------------------  Imports  ------------------------------
import math


# ------------------------------  Functions  ------------------------------
def TheAmazingFunction(Arr: list, K: int):
    Forward = []  # Counts The Number Of Even And Odd While Moving Forward        [Even, Odd]
    Backward = []  # "        "                   "                Backward
    ToBeSubtracted = [0, 0]
    PriceList = dict()
    Answer = 0
    # --------------------  SEPARATOR  --------------------
    for i in range(len(Arr)):
        j = len(Arr) - i - 1
        Forward.append([])
        Backward.insert(0, [])
        # --------------------  SEPARATOR  --------------------
        if i != 0:
            Forward[i] = Forward[i - 1].copy()
        else:
            Forward[i] = [0, 0]
        if Arr[i] % 2 == 0:
            Forward[i][0] += 1
        else:
            Forward[i][1] += 1
        # --------------------  SEPARATOR  --------------------
        if j != len(Arr) - 1:
            Backward[0] = Backward[1].copy()
        else:
            Backward[0] = [0, 0]
        if Arr[j] % 2 == 0:
            Backward[0][0] += 1
        else:
            Backward[0][1] += 1
        # --------------------  SEPARATOR  --------------------
    for i in range(1, len(Arr)-2, 2):
        # --------------------  SEPARATOR  --------------------
        TempForward = Forward[i].copy()
        TempForward[0] -= ToBeSubtracted[0]
        TempForward[1] -= ToBeSubtracted[1]
        # --------------------  SEPARATOR  --------------------
        if (TempForward[0] == TempForward[1]) and \
                (Backward[i + 1][0] == Backward[i + 1][1]) and \
                (abs(Arr[i] - Arr[i + 1]) <= K):
            if PriceList.get(abs(Arr[i] - Arr[i + 1])) is None:
                PriceList.update({abs(Arr[i] - Arr[i + 1]): 1})
            else:
                PriceList.update({abs(Arr[i] - Arr[i + 1]): PriceList.get(abs(Arr[i] - Arr[i + 1]))+1})
            ToBeSubtracted = Forward[i].copy()
    # --------------------  SEPARATOR  --------------------
    Prices = list(PriceList.keys())
    Prices.sort()
    # --------------------  SEPARATOR  --------------------
    for i in range(len(Prices)):
        if K == 0:
            break
        else:
            if Prices[i]*PriceList.get(Prices[i]) <= K:
                Answer += PriceList.get(Prices[i])
                K -= Prices[i]*PriceList.get(Prices[i])
            else:
                Answer += math.floor(K / Prices[i])
                K -= math.floor(K / Prices[i]) * Prices[i]
    return Answer


# ------------------------------  Driver Code  ------------------------------
N, B = list(map(int, input().split()))
myList = list(map(int, input().split()))
print(TheAmazingFunction(myList, B))
# ------------------------------  SEPARATOR  ------------------------------
