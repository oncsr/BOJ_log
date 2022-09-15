n=input()
while n!='0':
    a=n[-1:-len(n)-1:-1]
    if a==n:
        print("yes")
    else:
        print("no")
    n=input()
