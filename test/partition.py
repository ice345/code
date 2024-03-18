"""def partitions(n,m):
    if n<0 or m==0: 
        return 0
    else:
        exat_match=0
        if n==m:
            exat_match=1
        with_count=partitions(n-m,m)
        without_count=partitions(n,m-1)
        return exat_match+without_count+with_count
print(partitions(6,4))"""
def partition(n,m):
    if n>0 and m>0:
        if n==m:
            yield str(m)
        else:
            for i in partition(n-m,m):
                yield i + "+" + str(m)
        yield from partition(n,m-1)
t=partition(60,34)
"""s=list(t)
print(len(s))"""
for _ in range(34000):
    print(next(t))