def pi(num_terms):
    pi = 0.0
    realpi = 0.0
    if num_terms > 0:
        for k in range(0, num_terms):
            pi += (-1)**(k) / (2*k + 1)
    return pi*4
def vol(r,n,pi1):
    volume = 0
    for i in range(1, n):
        volume += pi1*(r**2-((i-1)*h)**2)*h
    return volume
r = float(input("Radius: "))
n = int(input("Number of cylinders: "))
num_terms = int(input("Number of terms to estimate pi: "))
h = r/n
print(pi(num_terms), vol(r,n,pi(num_terms)))
