# Problem Link:             https://codeforces.com/problemset/problem/118/B
# Problem Status:           Accepted.
# --------------- Separator ---------------
def TheAmazingFunction(A: int):
    length = A + 1
    width = (2*A) + 1
    Grid = []
    row = []
    for i in range(width):
        row.append(".")
    for i in range(0, length):
        Grid.append(row.copy())
    for i in range(A+1):
        index_1 = A
        index_2 = A
        val = i
        remaining = (2*i)+1
        while remaining > 0:
            Grid[i][index_1] = val
            Grid[i][index_2] = val
            if index_1 != index_2:
                remaining -= 2
            else:
                remaining -= 1
            index_1 -= 1
            index_2 += 1
            val -= 1
    showAns(Grid, A)


def showAns(Arr: list[list], A):
    for i in range(len(Arr)):
        for j in range(len(Arr[0])):
            if Arr[i][j] == ".":
                print(" ", end=" ")
            else:
                if Arr[i][j] == 0 and j >= A:
                    print(Arr[i][j], end="")
                    break
                else:
                    print(Arr[i][j], end=" ")
        print()
    for i in range(len(Arr)-2, -1, -1):
        for j in range(len(Arr[0])):
            if Arr[i][j] == ".":
                print(" ", end=" ")
            else:
                if Arr[i][j] == 0 and j >= A:
                    print(Arr[i][j], end="")
                    break
                else:
                    print(Arr[i][j], end=" ")
        print()


# --------------- Separator ---------------
N = int(input())
TheAmazingFunction(N)
# --------------- Separator ---------------
