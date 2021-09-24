import math
n= list(map(int, (input().split())))
def gcd(a,b):
    if (b == 0):
         return a
    return gcd(b, a%b)


# print(gcd(math.factorial(n[0]), math.factorial(n[1])))
# print(math.factorial(8))
n.sort()
print(math.factorial(n[0]))