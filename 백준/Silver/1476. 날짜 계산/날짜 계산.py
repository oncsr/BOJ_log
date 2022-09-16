a, b, c = input().split()
e, s, m = int(a), int(b), int(c)
E, S, M = 1, 1, 1
for i in range(1, 15*28*19 + 1):
    if E == e and S == s and M == m:
        print(i)
        break
    else:
        E, S, M = E + 1, S + 1, M + 1
        if E > 15:
            E = 1
        if S > 28:
            S = 1
        if M > 19:
            M = 1