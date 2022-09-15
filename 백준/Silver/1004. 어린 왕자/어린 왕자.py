t = int(input())

for i in range(t):
    data1 = input()
    x1,y1,x2,y2 = data1.split()
    x1,y1,x2,y2 = int(x1),int(y1),int(x2),int(y2)
    n = int(input())
    data2 = []
    for j in range(n):
        data2.append(list(input().split()))

    origin = 0
    destin = 0
    for circle in data2:
        chk = 0
        l1_2 = (int(circle[0])-x1)**2 + (int(circle[1])-y1)**2
        l2_2 = (int(circle[0])-x2)**2 + (int(circle[1])-y2)**2
        if l1_2 < int(circle[2])**2:
            chk += 1
            origin += 1
        if l2_2 < int(circle[2])**2:
            chk += 1
            destin += 1
        if chk == 2:
            origin -= 1
            destin -= 1
        
    print(origin + destin)