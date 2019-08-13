__author__ = 'Liang Wang'
__date__  = '2019.Aug.11'

'''
Define function: f(x,y,z) = (x^(y!))%z
Request get a quick ouput,  even for y or z is very big number.

'''

def pow_mod(x, y, z):
    "Calculate (x ** y) % z efficiently."
    res = 1
    while y:
        if y & 1:
            res = res * x % z
        y >>= 1
        x = x % z
        x = x * x 
    return res

def f(x, y, z):
    if x % z == 0: return 0
    if y == 0: return x % z
    res = 1

    for i in range(1, y+1):
        if i == 1: res = x % z
        else:
            res = pow_mod(res, i, z)
#            res = pow(res, i, z) # also you can invoke python api pow function directly
    return res


assert f(2, 1, 2) == 0 
assert f(3, 3, 2) == 1
assert f(1, 100000, 1) == 0
assert f(1, 100000, 2) == 1
assert f(99036, 92879, 77028) == 0
assert f(57582, 1465, 57582) == 0
assert f(14916, 63624, 37968) == 32544
assert f(48778, 6070, 89146) == 57188

print("Congratulation! Your function pass all test cases.") 

