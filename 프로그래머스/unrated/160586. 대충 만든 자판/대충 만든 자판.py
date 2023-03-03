def solution(keymap, targets):
    answer = []

    arr = [ 0 for i in range(26) ]
    for i in keymap:
        for j in range(len(i)):
            n = j+1
            if arr[ord(i[j])-ord('A')] == 0:
                arr[ord(i[j])-ord('A')] = n
            else:
                arr[ord(i[j])-ord('A')] = min(arr[ord(i[j])-ord('A')], n)

    for i in targets:
        s = 0
        for j in i:
            if arr[ord(j)-ord('A')] == 0:
                s = -1
                break
            s += arr[ord(j)-ord('A')]
        answer.append(s)

    return answer
                