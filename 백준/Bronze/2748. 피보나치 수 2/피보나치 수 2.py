i = 0
j = 1
cnt = 2
num = i+j
n = int(input())
if n == 1:  print(j)
else:
    while cnt != n:
        temp = num
        num += j
        j = temp
        cnt += 1
    print(num)