def search(f):
    x=0
    while True:
        if f(x):
            return x
        x+=1
def square(x):
    return x*x
def positive(x):
    return max(pow(x,2)-130,0)
def inverse(g):
    """使得g(f(x))=x,y=f(x),g(y)=x"""
    #return lambda x:(lambda y:g(x)==y)#这样就不行，因为x你单单这里不迭代，无法求出想要的结果，应该要配合search这函数循环用
    return lambda y:(search(lambda x:g(x)==y))#这样的话就可以用到了search的循环来求出结果
"""返回一个表达式，然后一个变量等于表达式，在变量后再注入值使得可以求解"""
print(search(positive))
sqrt=inverse(square)
print(sqrt(144))
#连起来就是sqrt(144)=inverse(square)[inverse(g)](144)[y]
def is_prime(x):
    i=2
    while(i<x):
        if(x%i==0):
            return False
        i+=1
    return True 
print(is_prime(9))