def divisor (a,b):
    if a<b:
        c=b
        b=a
        a=c
    for i in range(1, b+1):
        if a%i==0:
            x=a%i
        if b%i==0:
            y=b%i
        if x==y:
            z=i
    return z
a = int(input())
b = int(input())

print(divisor(a,b))


