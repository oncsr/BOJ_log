g,s=1,0
for i in input():s+=ord(i)%2*g;g*=2
print(s%1000000007)