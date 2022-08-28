# Problem Link:     https://codeforces.com/problemset/problem/465/B
# Problem Status:   Accepted.
# -------------------- SEPARATOR --------------------
def TheAmazingFunction(myList: list):
    Number_Of_Operations = 0
    Current_Position = -1 # Out Of The List
    for i in range(len(myList)):
        if myList[i] == 1:
            if Current_Position == -1:
                Number_Of_Operations += 1
                Current_Position = i

            else:
                if i - Current_Position > 1:
                    Number_Of_Operations += 2
                    Current_Position = i
                else:
                    Number_Of_Operations += 1
                    Current_Position = i
    return Number_Of_Operations


# -------------------- SEPARATOR --------------------
N = int(input())
A = list(map(int, input().split()))
print(TheAmazingFunction(A))
# -------------------- SEPARATOR --------------------
