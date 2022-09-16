n=input().split(':')
m=input().split(':')
n = int(n[0])*3600+int(n[1])*60+int(n[2])
m = int(m[0])*3600+int(m[1])*60+int(m[2])
if n>m: m+=86400
ans=m-n
ans_str=""
if len(str(ans//3600)) == 1:    ans_str+=('0'+str(ans//3600)+':')
else:   ans_str+=(str(ans//3600)+':')
ans%=3600
if len(str(ans//60)) == 1:  ans_str+=('0'+str(ans//60)+':')
else:   ans_str+=(str(ans//60)+':')
ans%=60
if len(str(ans)) == 1:  ans_str+=('0'+str(ans))
else:   ans_str+=str(ans)
print(ans_str)