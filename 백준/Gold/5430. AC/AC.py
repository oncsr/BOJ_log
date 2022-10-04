n=int(input())
while n != 0:
    n-=1

    op = input()
    g=int(input())
    l = input()
    try:
        ll = list(map(int,l.rstrip(']').lstrip('[').split(',')))
        st = 0
        ed = len(ll)-1
        reverse = False
        err = False
        for i in op:
            if i == 'R':
                if reverse == True:
                    reverse = False
                else:
                    reverse = True
            elif i == 'D':
                if reverse == True:
                    ed -= 1
                else:
                    st += 1
            if st - 1 > ed:
                err = True
                break
        if err == True:
            print("error")
        else:
            ans = "["
            if reverse == True:
                for i in range(ed, st-1, -1):
                    ans += str(ll[i])
                    if i != st:
                        ans += ','
            else:
                for i in range(st, ed + 1):
                    ans += str(ll[i])
                    if i != ed:
                        ans += ','
            ans += ']'
            print(ans)
    except:
        if 'D' in op:
            print("error")
        else:
            print(l)
    
