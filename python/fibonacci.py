num = int(input("Insira um valor:\n"))

a = 0
b = 1
print(0)
print(1)
for i in range(num):
    fib = a + b
    print(fib)
    a = b
    b= fib
        