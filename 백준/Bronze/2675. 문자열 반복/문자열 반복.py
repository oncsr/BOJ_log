t = int(input())
list = []
for _ in range(t):
    list.append(input().split())
newlist = []
for case in list:
    word = ''
    for w in case[1]:
        for _ in range(int(case[0])):
            word = word + w
    newlist.append(word)
for i in range(t):
    print(newlist[i])