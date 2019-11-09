
def max(c, d):
    if c > d:
        return c
        
    else :
        return d

def karatsuba(x,y):
    if len(str(x)) < 2 or len(str(y)) < 2:
        return x*y

    n = max(len(str(x)),len(str(y))) // 2

    a = x // 10**(n)
    b = x % 10**(n)
    c = y // 10**(n)
    d = y % 10**(n)

    z0 = karatsuba(b,d)
    z1 = karatsuba((a+b), (c+d))
    z2 = karatsuba(a,c)

    return ((10**(2*n))*z2)+((10**n)*(z1-z2-z0))+z0

a = int(input("\nEnter the first number : "))
b = int(input("\n\nEnter the second number : "))

print("Multiplication : " + str(karatsuba(a,b)))