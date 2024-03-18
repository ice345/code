def inverse_cascade(n):
    grow(n)
    print(n)
    shrink(n)

def f_then_g(f, g, n):
    if n:
        f(n)
        g(n)

def grow(n):
        f_then_g(grow, print, n // 10)

def shrink(n):
    f_then_g(print, shrink, n // 10)

# 测试
inverse_cascade(1234)
"""
def inverse_cascade(n):
    grow(n)
    print(n)
    shrink(n)

def f_then_g(f, g, n):
    if n:
        f(n)
        g(n)

def grow(n):
    if n < 10:
        print(n)
    else:
        f_then_g(grow, print, n // 10)

def shrink(n):
    if n < 10:
        pass
    else:
        f_then_g(print, shrink, n // 10)
    print(n)

# 测试
inverse_cascade(1234)
"""