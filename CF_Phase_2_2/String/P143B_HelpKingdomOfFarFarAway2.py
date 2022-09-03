# Problem Link:         https://codeforces.com/problemset/problem/143/B
# Problem Status:       Accepted.
# ---------------------- SEPARATOR ----------------------
def TheAmazingFunction(S: str):
    Answer = ""
    # ------------- SEPARATOR -------------
    Count = 0
    if S.find('.') != -1:
        for i in range(S.find('.')-1, -1, -1):
            if S[i] == '-':
                break
            if Count == 3:
                Answer = ',' + Answer
                Count = 0
            Answer = S[i] + Answer
            Count += 1
        if S.find('.') <= len(S)-3:
            Answer += '.' + S[S.find('.')+1] + S[S.find('.')+2]
        else:
            Temp = ""
            i = S.find('.') + 1
            while i <= len(S)-1:
                Temp += S[i]
                i += 1
            if len(Temp) == 1:
                Temp += '0'
            Answer += '.' + Temp
    else:
        for i in range(len(S)-1, -1, -1):
            if S[i] == '-':
                break
            if Count == 3:
                Answer = ',' + Answer
                Count = 0
            Answer = S[i] + Answer
            Count += 1
        Answer += ".00"
    # ------------- SEPARATOR -------------
    Answer = '$' + Answer
    # ------------- SEPARATOR -------------
    if S[0] == '-':
        Answer = '(' + Answer + ')'
    # ------------- SEPARATOR -------------
    return Answer


# ---------------------- SEPARATOR ----------------------
Text = input()
print(TheAmazingFunction(Text))
# ---------------------- SEPARATOR ----------------------
