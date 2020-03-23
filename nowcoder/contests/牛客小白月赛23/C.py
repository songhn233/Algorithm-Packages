T = int(input())
for tim in range(T):
  n,m = [int(x) for x in input().split()]
  temp=max(0,n*(n-1)//2-m)
  l,r=0,n-1
  while l<r:
    mid=l+r>>1
    if (mid*(mid+1)>>1)>=temp:
      r=mid
    else:
      l=mid+1
  print(n-l)