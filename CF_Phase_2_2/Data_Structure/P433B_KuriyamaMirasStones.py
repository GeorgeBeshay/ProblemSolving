# Problem Link:      https://codeforces.com/problemset/problem/433/B
# Problem Status:    Accepted.
# ------------------------------- SEPARATOR -------------------------------
# IDEA:
#   Two versions of the array should be available, the sorted one, and the given one
#   Create two sum arrays for each version, in which the sumArray[i] is the sum of A[i] up to A[n]
# ------------------------------- SEPARATOR -------------------------------
def TheAmazingFunction(H, Array: list):
    # ----------------------------
    sumArray = []
    for i in range(len(Array)):
        sumArray.append(0)
    sumArray[-1] = Array[-1]
    for i in range(len(Array)-2, -1, -1):
        sumArray[i] = sumArray[i+1] + Array[i]
    # ----------------------------
    sortedArray = Array.copy()
    sortedArray.sort()
    sortedSumArray = []
    for i in range(len(sortedArray)):
        sortedSumArray.append(0)
    sortedSumArray[-1] = sortedArray[-1]
    for i in range(len(sortedArray)-2, -1, -1):
        sortedSumArray[i] = sortedSumArray[i+1] + sortedArray[i]
    # ----------------------------
    while H > 0:
        H -= 1
        T, L, R = list(map(int, input().split()))
        L -= 1
        R -= 1
        if T == 1:
            print(sumArray[L] - sumArray[R] + Array[R])
        else:
            print(sortedSumArray[L] - sortedSumArray[R] + sortedArray[R])


# ------------------------------- SEPARATOR -------------------------------
N = int(input())
A = list(map(int, input().split()))
M = int(input())
TheAmazingFunction(M, A)
# ------------------------------- SEPARATOR -------------------------------
