import math
n = int(input())
qr = [list(map(int, input().split())) for _ in range(n)]

q = int(input())
ans = []

for i in range(q):
    t,d = map(int,input().split())
    cs = qr[t-1]
    
    res = 0
    if d % cs[0] == cs[1]:# and d >= cs[0]:
        res = d
    else:
        res = d + (cs[1] - d % cs[0])
        if res < d:
            res += cs[0] * math.ceil(((d - res) / cs[0]))
        
    ans.append(res)
    
print(*ans, sep="\n")