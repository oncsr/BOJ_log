import sys
for _ in range(3):
    a=map(int,sys.stdin.readline().split())
    cnt = 0
    for i in a:
        if i == 1:
            cnt += 1
    if cnt!=4:
        print(chr(68-cnt))
    else:
        print('E')