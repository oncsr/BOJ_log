a=input()
if a == 'F':    print(0.0)
else:
    r=69-ord(a[0])
    if a[1]=='+':   print(r+0.3)
    elif a[1]=='-': print(r-0.3)
    else:           print(float(r))