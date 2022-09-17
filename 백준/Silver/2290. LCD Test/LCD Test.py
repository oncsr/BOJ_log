def print_top(s, n):
    for i in n:
        print(' ',end='')
        if(i == '1' or i == '4'):
            print(' '*s,end='')
        else:
            print('-'*s,end='')
        print('  ', end='')
    print()

def print_mid1(s, n):
    for i in n:
        if(i == '1' or i == '2' or i == '3' or i == '7'):
            print(' ',end='')
        else:
            print('|',end='')
        print(' '*s,end='')
        if(i == '5' or i == '6'):
            print(' ',end='')
        else:
            print('|',end='')
        print(' ',end='')
    print()

def print_mid2(s, n):
    for i in n:
        print(' ',end='')
        if(i == '1' or i == '7' or i == '0'):
            print(' '*s,end='')
        else:
            print('-'*s,end='')
        print('  ',end='')
    print()

def print_mid3(s, n):
    for i in n:
        if(i == '2' or i == '6' or i == '8' or i == '0'):
            print('|',end='')
        else:
            print(' ',end='')
        print(' '*s,end='')
        if(i == '2'):
            print(' ',end='')
        else:
            print('|',end='')
        print(' ',end='')
    print()

def print_bot(s, n):
    for i in n:
        print(' ',end='')
        if(i == '1' or i == '4' or i == '7'):
            print(' '*s,end='')
        else:
            print('-'*s,end='')
        print('  ',end='')


s, n = input().split()
s = int(s)

print_top(s, n)
for i in range(s):
    print_mid1(s, n)
print_mid2(s, n)
for i in range(s):
    print_mid3(s, n)
print_bot(s, n)
