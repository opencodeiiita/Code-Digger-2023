from collections import*
def d(n):
 v[n]=1
 for n in g[n]:
  if not v[n]:d(n)
n,e=map(int,input().split())
g=defaultdict(list)
v=[0]*(n+1)
for _ in range(e):
 x,y=map(int,input().split())
 g[x]+=y,
 g[y]+=x,
d(1)
z=[i for i in range(1,n+1)if v[i]]
print(len(z))
print(*z[1:])
