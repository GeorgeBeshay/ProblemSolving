# Problem Link:     https://codeforces.com/problemset/problem/234/B
# Problem Status:   Accepted.
# -------------------------------- SEPARATOR --------------------------------
def TheAmazingFunction(Arr: list, Q):
    TableOfIndices = dict()
    for i in range(len(Arr)):
        if TableOfIndices.get(Arr[i]) is None:
            TableOfIndices.update({Arr[i]: [i+1]})
        else:
            tempList = TableOfIndices.get(Arr[i])
            tempList.append(i+1)
            TableOfIndices.update({Arr[i]: tempList})
    Arr.sort()
    OutputFile = open("output.txt", 'w')
    OutputFile.write(str(Arr[-Q]) + "\n")
    tempString = ""
    for i in range(-Q, 0):
        tempString += str(TableOfIndices.get(Arr[i])[0])
        TableOfIndices.get(Arr[i]).__delitem__(0)
        tempString += " "
    OutputFile.write(tempString)
    OutputFile.close()


# -------------------------------- SEPARATOR --------------------------------
myFile = open("input.txt", 'r')        # Must Create an Input File !!
N, K = list(map(int, myFile.readline().split()))
A = list(map(int, myFile.readline().split()))
myFile.close()
TheAmazingFunction(A, K)
