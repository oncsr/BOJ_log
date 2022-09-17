n=int(input())
a=map(int,input().split())
score=0
plus=1
for i in a:
    if i==1:
        score+=plus
        plus+=1
    else:
        plus=1
print(score)