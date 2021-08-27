def f1(n):
    count = 0
    while (n > 0):
        n = n//2
        count = count + 1
        print(n)
    return count
def f2(count):
    n = 1
    while(count > 0):
        n = n*2
        count = count - 1
    return n

x = 65
y = f1(x)
z = f2(y)
print(x)
print(y)
print(z)