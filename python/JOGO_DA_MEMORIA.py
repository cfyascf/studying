from random import randint
from time import sleep
import os
        
arrayRand = []
arrayUser = []
points = 0
j = 1
flag = 0

while flag != 1:
    os.system('cls')
    
    arrayRand.append(randint(1, 100))
    for i in range(j):
        sleep(0.5)
        print(arrayRand[i])
        sleep(1.2)
        os.system('cls')
        
    print("Voce lembra de todos os valores que apareceram na tela? Duvido!\n")
    
    for i in range(j):
        arrayUser.append(int(input(f"Numero {i+1}: \n")))
        if arrayUser[i] == arrayRand[i]:
            points += 1
            print(f"Pontos: {points}")
            print()
        elif arrayUser[i] != arrayRand[i]:
            print("Voce errou! Acabou o jogo\n")
            print("A sequencia era:\n")
            print(arrayRand)
            flag = 1
            break
        
    arrayUser = []
    j += 1
 