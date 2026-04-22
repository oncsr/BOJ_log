n=int(input())
s=0
while n > 0:
    if '1' in str(n):
        s += str(n).count('1')
        try:
            n = int(str(n).replace('1',''))
        except:
            print(s)
            exit()

    else:
        n-=1
        s+=1
print(s)
