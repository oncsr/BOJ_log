t = int(input())
for i in range(t):
    a, b = input().split()
    a, b = int(a), int(b)

    cycle = a % 10
    result = a
    num_list = []
    while not(str(result)[-1] == str(cycle) and len(num_list) != 0):
        num_list.append(int(str(result)[-1]))
        result *= a

    c = num_list[(b%len(num_list))-1]
    if c == 0:  print(10)
    else:       print(c)