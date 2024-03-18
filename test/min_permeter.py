def width(area,height):
    assert area%height == 0
    return area//height
def perimeter(width,height):
    return 2*(height+width)
def divisors(n):
    return [1]+[x for x in range(2,n) if n%x==0]
def min_permeter(area):
    height=divisors(area)
    perimeter_=[perimeter(width(area,h),h) for h in height]
    return min(perimeter_)
print([min_permeter(n) for n in range(1,50)])