num = int(input("Insira um valor\n"))
flag = 0

for i in range(2, num):
    if num % i == 0:
        flag += 1
    else:
        flag = 0
    
if flag > 0:
    print("Numero nao eh primo\n")
elif flag == 0:
    print("Numero eh primo\n")        

    