s=input()
o=['+','-','*','//','%']
for i in o:
    print(eval(s.replace(' ',i)))