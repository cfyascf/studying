from random import randint

pc = randint(0, 10)
points = 0
num = 1

print("\n--- JOGO DE PAR OU IMPAR ---\n")

while num != 0:
    num = int(input("Insira um valor (0 para parar):\n"))
    choice = input("Par ou impar?\n")
    
    if (num + pc) % 2 == 0:
        result = 'par'
    else:
        result = 'impar'
       
    print(f"O computador jogou {pc}\n")
    if result == choice:
        print("Voce ganhou\n")
        points += 1
        print(f"Seus pontos: {points}\n")
    elif result != choice:
        print("Voce perdeu\n")
        