from operator import add
def keep_if(filter_fn,s):#用来求一个列表内符合filter_fn操作的数组成列表
    return [x for x in s if filter_fn(x)]
def reduce(reduce_fn,s,initial):#用来对列表内的数进行操作的
    reduced = initial
    for x in s:
        reduced = reduce_fn(reduced,x)
    return reduced
def divisors_of(n):#用来求n的因子的列表
    divides_n=lambda x: n%x==0
    return [1]+keep_if(divides_n,range(2,n))
def sum_of_divisors(n):
    return reduce(add,divisors_of(n),0)
def perfect(n):
    return sum_of_divisors(n)==n
print(keep_if(perfect,range(1,10000)))