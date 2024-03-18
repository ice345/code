def spilt(n):
    return n//10,n%10


def sum_digits(n):
    all_but_last,last=n//10,n%10
    if n<10:
        return last
    else:
        return last+sum_digits(all_but_last)


def luhn_sum(n):
    if n<10:
        return n
    else:
        all_but_last,last=spilt(n)
        return luhn_sum_double(all_but_last)+last



def luhn_sum_double(n):
    all_but_last,last=spilt(n)#这样处理all_but_last最后一位就又变为奇数位了
    luhn_digits=sum_digits(last*2)#这样是为了防止出现last*2大于10的情况
    if n<10:
        return luhn_digits
        # return last*2#若此时last*2大于10就不符合要求了，所以还要用sum_digits函数
    else:
        return luhn_digits+luhn_sum(all_but_last)

def luhn_sum_judge(n):
    if n<10:
        return n
    else:
        all_but_last,last=spilt(n)
        total=luhn_sum_double(all_but_last)+last
    if(total%10==0):
        print("这是个合规的号码")
    else:
        print("这是个不合规的号码")
