from collections import Counter
t= int(input())
for k in range(t):
    n= int(input())
    a= list(map(int,input().split(" ")))
    c= Counter(a)
    val= list(c.values())

    val.sort()
    if val[-1]%2==0:
        val[-1]= val[-1]//2
    else:
        val[-1] = (val[-1]+1)//2
    val.sort()
    print(val[-1])